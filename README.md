# Operating Systems Laboratory: Complete Codebase & Lab Manual

A complete, structured, and thoroughly tested laboratory manual and source code repository for the **Operating Systems (OS) Laboratory**, based directly on the official curriculum syllabus.

Every experiment contains:
- **Fully working, cleanly formatted, and well-commented source code** (.c / .sh).
- **Comprehensive README.md documentation** covering:
  - Experiment Aim and Objectives.
  - Course Outcomes (CO).
  - Theoretical background & architectural concepts.
  - Algorithms and step-by-step logic.
  - Exact compilation and execution commands.
  - Sample test inputs and expected outputs (verified against manual).
  - In-depth **Viva Voce & Interview Questions with detailed Answers**.

---

## Laboratory Index & Directory Structure

```
OS/
├── OS Manual.pdf                                     # Original reference lab manual
├── README.md                                         # Master repository index
│
├── Experiment_01_Basic_Unix_Commands/                 # Exp 1: Unix Command Essentials
│   ├── README.md                                     # In-depth theory, commands & viva questions
│   ├── demo_commands.sh                              # Automated demonstration bash script
│   └── commands_cheatsheet.txt                       # Quick-reference command sheet
│
├── Experiment_02_Shell_Scripting_File_Handling/      # Exp 2: Shell Scripting & File Operations
│   ├── README.md                                     # Theory, operators & viva questions
│   ├── 01_first.sh                                   # Hello world script
│   ├── 02_file_check_read.sh                         # File check and cat display
│   ├── 03_check_file_exists.sh                       # Conditional file existence check
│   ├── 04_create_write_file.sh                       # Create file and write content
│   ├── 05_count_lines_words_chars.sh                 # Count lines/words/chars (wc)
│   ├── 06_append_file.sh                             # Append content (>>)
│   ├── 07_display_line_by_line.sh                    # Line-by-line reading loop
│   ├── 08_copy_file.sh                               # Copy file (cp)
│   ├── 09_search_word.sh                             # Search word (grep)
│   ├── 10_delete_file.sh                             # Delete file (rm)
│   └── 11_file_manager_menu.sh                       # Integrated interactive menu script
│
├── Experiment_03_Grep_Awk_Sed/                       # Exp 3: Pattern Matching & Text Filtering
│   ├── README.md                                     # In-depth theory, regex & viva questions
│   ├── 01_grep_demo.sh                               # grep search with flags (-i, -n, -c, -v)
│   ├── 02_awk_demo.sh                                # awk field extraction & condition filters
│   ├── 03_sed_demo.sh                                # sed substitution & line deletions
│   ├── 04_combined_demo.sh                           # Combined pipeline script
│   └── data/                                         # Test dataset files
│       ├── students.txt
│       ├── marks.txt
│       ├── employees.txt
│       ├── animals.txt
│       └── log.txt
│
├── Experiment_04_CPU_Scheduling/                     # Exp 4: CPU Scheduling Algorithms
│   ├── README.md                                     # Gantt charts, formulas, theory & viva Q&A
│   ├── fcfs.c                                        # First Come First Serve scheduling
│   ├── sjf.c                                         # Shortest Job First scheduling
│   └── priority.c                                    # Priority scheduling
│
├── Experiment_05_Page_Replacement/                   # Exp 5: Page Replacement Algorithms
│   ├── README.md                                     # Virtual memory, Belady's Anomaly & viva Q&A
│   ├── fifo.c                                        # FIFO page replacement
│   ├── optimal.c                                     # Optimal page replacement
│   └── lru.c                                         # LRU page replacement
│
├── Experiment_06_Concurrency_Processes_Threads/      # Exp 6: fork(), vfork(), POSIX Threads
│   ├── README.md                                     # Process vs thread, memory model & viva Q&A
│   ├── fork_vfork.c                                  # fork() and vfork() demonstration
│   └── pthread_demo.c                                # Multithreading with pthreads
│
├── Experiment_07_Process_Synchronization/            # Exp 7: Mutex, Semaphores, Condition Variables
│   ├── README.md                                     # Critical Section, race conditions & viva Q&A
│   └── sync_primitives.c                             # Thread synchronization primitives
│
├── Experiment_08_Producer_Consumer_Bankers/          # Exp 8: Producer-Consumer & Banker's Algorithm
│   ├── README.md                                     # Bounded buffer, deadlock avoidance & viva Q&A
│   ├── producer_consumer.c                           # Producer-Consumer circular buffer
│   └── bankers_algorithm.c                           # Banker's safety algorithm & safe sequence
│
├── Experiment_09_Memory_Allocation/                  # Exp 9: Dynamic Memory Allocation
│   ├── README.md                                     # Internal/External fragmentation & viva Q&A
│   ├── memory_allocation.c                           # Unified comparison of First, Best & Worst Fit
│   ├── first_fit.c                                   # Standalone First Fit
│   ├── best_fit.c                                    # Standalone Best Fit
│   └── worst_fit.c                                   # Standalone Worst Fit
│
└── Experiment_10_Disk_Scheduling/                    # Exp 10: Disk Head Scheduling Algorithms
    ├── README.md                                     # Head movement trace, seek time & viva Q&A
    ├── fcfs_disk.c                                   # FCFS disk scheduling
    ├── sstf_disk.c                                   # Shortest Seek Time First
    ├── scan_disk.c                                   # SCAN (Elevator) algorithm
    └── cscan_disk.c                                  # C-SCAN (Circular SCAN) algorithm
```

---

## Summary of Experiments

| Exp No. | Topic / Aim | Key Programs | Concepts Covered |
| :---: | :--- | :--- | :--- |
| **01** | [Basic Unix Commands](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_01_Basic_Unix_Commands/README.md) | `demo_commands.sh` | `pwd`, `cd`, `mkdir`, `cp`, `mv`, `rm`, `ls`, `chmod`, `ps`, `kill`, `df`, `du` |
| **02** | [Shell Scripting File Handling](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_02_Shell_Scripting_File_Handling/README.md) | `01_first.sh` to `11_file_manager_menu.sh` | Shell scripting, condition test `[ -f ]`, `wc`, `>`, `>>`, `while read` |
| **03** | [Text Processing with Grep, Awk, Sed](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_03_Grep_Awk_Sed/README.md) | `01_grep_demo.sh` to `04_combined_demo.sh` | Pattern matching, field extraction `$1`, filtering `$3 > 50`, `sed 's/old/new/g'`, line deletion `3d` |
| **04** | [CPU Scheduling Algorithms](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_04_CPU_Scheduling/README.md) | `fcfs.c`, `sjf.c`, `priority.c` | Completion Time ($CT$), Turnaround Time ($TAT$), Waiting Time ($WT$), Convoy effect, Starvation |
| **05** | [Page Replacement Algorithms](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_05_Page_Replacement/README.md) | `fifo.c`, `optimal.c`, `lru.c` | Virtual memory, Page faults, Page hits, Belady's Anomaly, Reference string trace |
| **06** | [Concurrency (Processes & Threads)](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_06_Concurrency_Processes_Threads/README.md) | `fork_vfork.c`, `pthread_demo.c` | System calls `fork()`, `vfork()`, copy-on-write, `_exit()`, `pthread_create()`, `pthread_join()` |
| **07** | [Process Synchronization](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_07_Process_Synchronization/README.md) | `sync_primitives.c` | Mutual exclusion, Mutex lock, Binary semaphore, Condition variables, Race conditions |
| **08** | [Producer-Consumer & Banker's Algorithm](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_08_Producer_Consumer_Bankers/README.md) | `producer_consumer.c`, `bankers_algorithm.c` | Cooperating processes, Bounded buffer, Deadlock conditions, Safe state, Safe sequence |
| **09** | [Dynamic Memory Allocation](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_09_Memory_Allocation/README.md) | `memory_allocation.c`, `first_fit.c`, `best_fit.c`, `worst_fit.c` | First Fit, Best Fit, Worst Fit, Internal & External fragmentation, Compaction |
| **10** | [Disk Scheduling Algorithms](file:///c:/Users/meena%20shah/Desktop/OS/Experiment_10_Disk_Scheduling/README.md) | `fcfs_disk.c`, `sstf_disk.c`, `scan_disk.c`, `cscan_disk.c` | Seek time calculation, SSTF starvation, SCAN elevator sweep, C-SCAN circular return |

---

## Requirements & Environment Setup

### 1. Requirements
- **Operating System:** Linux / Ubuntu (recommended via VirtualBox, WSL, or native installation as noted in the manual).
- **C Compiler:** GCC (`gcc --version`).
- **Shell Interpreter:** GNU Bash (`/bin/bash`).

### 2. General Compilation and Run Guide

#### Running Shell Scripts (Experiments 1, 2, 3)
```bash
# Give execute permissions
chmod +x *.sh

# Execute a script
./script_name.sh
```

#### Compiling and Running Standard C Programs (Experiments 4, 5, 8, 9, 10)
```bash
gcc -Wall -o program_name program_name.c
./program_name
```

#### Compiling Multithreaded / POSIX C Programs (Experiments 6, 7)
```bash
# Link against pthread and realtime libraries
gcc -Wall -pthread -o program_name program_name.c
./program_name
```

---

## Lab Viva Voce Quick Revision Checklist

1. **What is a System Call?**
   - The programmatic interface by which an executing user application requests privileged services from the OS kernel (e.g., `fork`, `read`, `write`, `open`, `kill`).
2. **What are the 4 conditions required for Deadlock?**
   - Mutual Exclusion, Hold and Wait, No Preemption, and Circular Wait.
3. **What is the difference between Preemptive and Non-Preemptive scheduling?**
   - Non-preemptive processes retain CPU until voluntary release; preemptive processes can be interrupted by the OS scheduler (e.g., higher priority arrival or quantum expiry).
4. **Why does Belady's Anomaly occur only in FIFO and not in LRU or Optimal?**
   - FIFO is not a stack algorithm. Increasing the number of frame allocations does not guarantee that the set of pages in memory with $M$ frames is a subset of pages in memory with $M+1$ frames.
5. **Why is Banker's Algorithm called an avoidance algorithm rather than prevention?**
   - It dynamically analyzes every resource request before granting it to ensure the transition leads to a known safe state where no circular wait can materialize.

#   O S - F r o m - S c r a t c h  
 