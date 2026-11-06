# Experiment 7: Synchronization Mechanisms (Semaphores, Mutex Locks, Condition Variables)

> **Author:** Yug Shah (TYCSE)  
> **Repository:** Os from scratch  
> **Course:** Operating Systems Lab  

## 1. Aim
To implement synchronization mechanisms using semaphores, mutex locks, and condition variables for controlling concurrent access to shared resources.

## 2. Course Outcome & Learning Objectives
- **Course Outcome:** Implement process synchronization techniques, and analyze deadlock conditions with appropriate prevention, avoidance, and recovery strategies.
- **Learning Objectives:**
  - Understand race conditions and the Critical Section Problem.
  - Implement Mutex Locks for strict mutual exclusion.
  - Use counting and binary semaphores for resource signaling and coordination.
  - Apply Condition Variables for thread notification and wait queues.
  - Prevent data inconsistencies in multi-threaded programs.

---

## 3. Related Theory

### 3.1 The Critical Section Problem
A **Critical Section** is a code segment where shared variables, tables, or files are accessed or modified. If multiple threads enter the critical section concurrently without synchronization, a **race condition** occurs, leaving shared state corrupted.

Any valid solution to the critical section problem must satisfy three criteria:
1. **Mutual Exclusion:** If process $P_i$ is executing in its critical section, no other processes can execute in their critical sections.
2. **Progress:** If no process is executing in its critical section and some processes wish to enter, only those processes not executing in their remainder sections can participate in deciding which will enter next.
3. **Bounded Waiting:** A bound must exist on the number of times other processes are allowed to enter their critical sections after a process has made a request to enter and before that request is granted.

---

### 3.2 Comparison of Synchronization Primitives

| Primitive | Mechanism | Key API Calls | Typical Use Case |
| :--- | :--- | :--- | :--- |
| **Mutex Lock** | Binary locking ownership primitive (locked / unlocked). Only the thread that locked the mutex can unlock it. | `pthread_mutex_lock()`<br>`pthread_mutex_unlock()` | Protecting a shared variable or data structure from concurrent updates. |
| **Binary Semaphore** | Integer value initialized to `1`. Down operation (`sem_wait`) decrements; Up operation (`sem_post`) increments. Can be signaled across threads/processes. | `sem_wait()`<br>`sem_post()` | Mutual exclusion and cross-thread event signaling. |
| **Counting Semaphore** | Integer value initialized to $N > 1$. Controls access to a finite pool of identical resource instances. | `sem_wait()`<br>`sem_post()` | Bounded buffers, connection pools, thread pool limiters. |
| **Condition Variable** | Signaling queue where threads can sleep atomically until another thread signals a condition change. Must be paired with a mutex. | `pthread_cond_wait()`<br>`pthread_cond_signal()`<br>`pthread_cond_broadcast()` | Producer-consumer coordination, barrier synchronization. |

---

## 4. Source Files

- `sync_primitives.c` – Implements all three primitives within a single program demonstrating thread-safe counter increment, binary semaphore critical section, and condition variable signaling.

---

## 5. How to Compile and Run (on Linux / Ubuntu)

### Compilation
```bash
gcc -Wall -pthread -o sync_primitives sync_primitives.c
```

### Execution
```bash
./sync_primitives
```

---

## 6. Sample Output (from Lab Manual)

```text
=== Process Synchronization Mechanisms ===

Mutex Lock: shared = 1
Semaphore: Thread inside critical section
Condition Variable: Waiting...
Condition Variable: Thread resumed

All threads finished cleanly. Synchronization demo complete.
```

---

## 7. Viva Voce & Interview Questions with Answers

### Q1: What is a Race Condition? Give an example.
**Answer:**
A race condition is an undesirable situation that occurs when a system attempts to perform two or more operations at the same time, but because of the nature of the device or system, the operations must be done in the proper sequence to be done correctly.
*Example:* If two threads simultaneously read `count = 5` and then both execute `count++`, both write back `6`. Instead of the correct value `7`, one increment is lost.

### Q2: How does a Mutex differ from a Semaphore?
**Answer:**
- **Ownership:** A mutex has an concept of ownership—only the specific thread that acquired the mutex can release it. A semaphore has no ownership; one thread can wait (`sem_wait`) while another thread signals (`sem_post`).
- **Capacity:** A mutex is strictly binary (0 or 1). A semaphore can be counting (integer value from 0 to $N$).
- **Use Case:** Mutex is optimized for mutual exclusion. Semaphores are primarily signaling mechanisms for synchronization and resource pool management.

### Q3: Why must `pthread_cond_wait()` be called while holding a mutex lock?
**Answer:**
`pthread_cond_wait()` atomically releases the mutex and places the calling thread on the condition wait list. When awakened by `pthread_cond_signal()`, it re-acquires the mutex before returning. Without holding the mutex, a **lost wakeup problem** could occur where a signal fires between checking a predicate condition and going to sleep.

### Q4: What is a Deadlock? Name the 4 necessary Coffman conditions.
**Answer:**
A deadlock is a state where a set of processes are blocked because each process holds a resource and waits for another resource held by some other process in the set.
The 4 necessary conditions are:
1. **Mutual Exclusion:** At least one resource must be held in a non-shareable mode.
2. **Hold and Wait:** A process must hold at least one resource and wait to acquire additional resources held by other processes.
3. **No Preemption:** Resources cannot be forcibly taken from a process holding them.
4. **Circular Wait:** A closed chain of processes exists such that each process holds a resource needed by the next process in the chain.

---

## 8. Conclusion
This experiment demonstrated how mutex locks, semaphores, and condition variables are utilized to enforce mutual exclusion and coordinate threads. Proper synchronization prevents race conditions and ensures deterministic, thread-safe program behavior.

