# Experiment 6: Concurrent Programming Using Processes and Threads (fork, vfork, pthreads)

> **Author:** Yug Shah (TYCSE)  
> **Repository:** Os from scratch  
> **Course:** Operating Systems Lab  

## 1. Aim
To study and implement concurrent programming using processes and threads, and to understand system calls such as `fork()` and `vfork()`.

## 2. Course Outcome & Learning Objectives
- **Course Outcome (CO):** Apply CPU scheduling algorithms and multithreading models to improve process performance and system throughput.
- **Learning Objectives:**
  - Understand the concept and architecture of concurrent execution in operating systems.
  - Implement process creation using UNIX system calls: `fork()` and `vfork()`.
  - Create, manage, synchronize, and join threads using the POSIX `pthread` library.
  - Contrast the memory models and resource footprints of processes vs threads.
  - Understand process address space isolation vs shared address space.

---

## 3. Related Theory

### 3.1 Process vs Thread

| Feature | Process | Thread (Lightweight Process) |
| :--- | :--- | :--- |
| **Address Space** | Private, isolated virtual memory address space. | Shares code, data, heap, and open file descriptors with other threads of the process. |
| **State Info** | Own PCB, memory map, file descriptors, stack, registers. | Own stack, program counter (PC), and CPU register set; shares heap and static variables. |
| **Creation Overhead** | High (memory allocation, page table creation). | Low (shares existing process memory). |
| **Context Switching** | Expensive (invalidates TLB caches, switches page directories). | Very fast (shares page tables, minimal cache thrashing). |
| **Communication** | Requires Inter-Process Communication (IPC: pipes, shared memory, sockets). | Direct memory access via shared variables. |
| **Crash Impact** | If one process crashes, others remain unaffected. | If one thread causes a segmentation fault, the entire process terminates. |

---

### 3.2 The `fork()` System Call
`fork()` creates an exact duplicate child process.
- **Return Value:**
  - To child process: returns `0`.
  - To parent process: returns the newly created child's Process ID (`PID > 0`).
  - On failure: returns `-1`.
- **Memory Model:** The child inherits a copy of the parent's address space. Modern kernels utilize **Copy-on-Write (COW)** so physical pages are only cloned when modified.

### 3.3 The `vfork()` System Call
`vfork()` creates a child process designed to invoke `execve()` immediately.
- Unlike `fork()`, `vfork()` **does not copy page tables**. The child shares the parent's address space directly.
- The parent process is **blocked / suspended** until the child terminates or calls `execve()`.
- The child must terminate using `_exit()` (not `exit()`), as `exit()` flushes the parent's I/O buffers.

### 3.4 POSIX Threads (`pthreads`)
The POSIX thread standard (`<pthread.h>`) provides APIs for multithreading:
- `pthread_create(&tid, attr, start_routine, arg)` : Spawns a new concurrent thread.
- `pthread_join(tid, &retval)` : Blocks the calling thread until the target thread finishes execution.
- `pthread_exit(retval)` : Terminates the calling thread.

---

## 4. Source Files

| File | Description |
| :--- | :--- |
| `fork_vfork.c` | Demonstrates process creation using both `fork()` and `vfork()` system calls. |
| `pthread_demo.c` | Creates and synchronizes concurrent worker threads with `pthread_create()` and `pthread_join()`. |

---

## 5. How to Compile and Run (on Linux / Ubuntu)

### Compilation
```bash
# Compile fork and vfork program
gcc -Wall -o fork_vfork fork_vfork.c

# Compile pthread program (note the -pthread flag)
gcc -Wall -pthread -o pthread_demo pthread_demo.c
```

### Execution
```bash
./fork_vfork
./pthread_demo
```

---

## 6. Sample Output

### 6.1 `fork_vfork` Output
```text
=== Process Creation Demonstration ===

--- 1. Testing fork() ---
Parent Process using fork (PID: 118458), Child PID: 118459
Child Process using fork (PID: 118459, Parent PID: 118458)

--- 2. Testing vfork() ---
Child Process using vfork (PID: 118460, Parent PID: 118458)
Parent Process after vfork (PID: 118458)

Both fork() and vfork() completed successfully.
```

### 6.2 `pthread_demo` Output
```text
=== POSIX Multithreading Demonstration ===
[Thread 1] Thread running iteration 0
[Thread 2] Thread running iteration 0
[Thread 1] Thread running iteration 1
[Thread 2] Thread running iteration 1
[Thread 1] Thread running iteration 2
[Thread 2] Thread running iteration 2
Main thread completed
```

---

## 7. Viva Voce & Interview Questions with Answers

### Q1: What does `fork()` return in the parent and the child?
**Answer:**
- In the **parent process**, `fork()` returns the positive Process ID (PID) of the child process.
- In the **child process**, `fork()` returns `0`.
- If process creation fails, `fork()` returns `-1`.

### Q2: Why is `_exit()` used instead of `exit()` in a `vfork()` child?
**Answer:**
Because `vfork()` shares the parent's memory and standard I/O stream buffers without copying them, calling `exit()` would flush and close file streams, free resources, or corrupt the parent's stack and state. `_exit()` safely halts the child without touching parent buffers.

### Q3: What is a Zombie Process? What is an Orphan Process?
**Answer:**
- **Zombie Process:** A process that has finished execution (via `exit`), but its entry still remains in the process table because its parent has not yet read its exit status with `wait()`.
- **Orphan Process:** A process whose parent has terminated before it. The operating system kernel automatically re-parents orphan processes to `init` (PID 1) or `systemd`, which reaps them upon termination.

### Q4: Why is multithreading faster than multiprocessing?
**Answer:**
Threads share the same virtual address space, file descriptor table, and heaps. Creating a thread does not require allocating new page tables or duplicating process control blocks. Context switching between threads in the same process does not invalidate the Translation Lookaside Buffer (TLB) or CPU caches.

### Q5: What is the purpose of `pthread_join()`?
**Answer:**
`pthread_join()` acts analogously to `wait()` for processes. It blocks the calling thread (usually the main thread) until the target thread terminates, preventing the process from exiting prematurely while background worker threads are still computing.

---

## 8. Conclusion
The experiment demonstrated the creation and lifecycle of processes and threads. Students gain first-hand understanding of parent-child concurrency with `fork()`, synchronous parent-blocking execution with `vfork()`, and parallel lightweight execution using POSIX threads.

