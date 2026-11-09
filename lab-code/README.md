# lab-code

Minimal, exam-ready implementations of the OS lab experiments. Only core logic — no validation, no verbose UI.

## Index

| Lab | Topic | Files |
|:---:|:---|:---|
| 1 | Basic Unix commands | `Lab_01_Basic_Unix_Commands/commands.sh` |
| 2 | Shell scripting & file handling | `Lab_02_Shell_File_Handling/file_ops.sh` |
| 3 | grep, awk, sed | `Lab_03_Grep_Awk_Sed/text_processing.sh` |
| 4 | CPU scheduling | `Lab_04_CPU_Scheduling/{fcfs,sjf,priority}.c` |
| 5 | Page replacement | `Lab_05_Page_Replacement/{fifo,lru,optimal}.c` |
| 6 | fork, vfork, pthreads | `Lab_06_Concurrency/{fork_vfork,pthread_demo}.c` |
| 7 | Synchronization | `Lab_07_Synchronization/sync_primitives.c` |
| 8 | Producer-consumer & Banker's | `Lab_08_Producer_Consumer_Bankers/{producer_consumer,bankers}.c` |
| 9 | Memory allocation | `Lab_09_Memory_Allocation/{first_fit,best_fit,worst_fit}.c` |
| 10 | Disk scheduling | `Lab_10_Disk_Scheduling/{fcfs_disk,sstf_disk,scan_disk,cscan_disk}.c` |

## Build

```bash
make            # all C programs
make clean
```

Or compile one file:

```bash
gcc -Wall -O2 -o fcfs Lab_04_CPU_Scheduling/fcfs.c
gcc -Wall -O2 -pthread -o sync_primitives Lab_07_Synchronization/sync_primitives.c
```

> Labs 6 and 7 need Linux/WSL (POSIX `fork`, `pthreads`).

## Run

```bash
bash Lab_01_Basic_Unix_Commands/commands.sh
bash Lab_02_Shell_File_Handling/file_ops.sh
bash Lab_03_Grep_Awk_Sed/text_processing.sh

./fcfs < sample_inputs/fcfs.txt
./sjf < sample_inputs/sjf.txt
./priority < sample_inputs/priority.txt
./fifo < sample_inputs/pages.txt
./lru < sample_inputs/pages.txt
./optimal < sample_inputs/pages.txt
./producer_consumer < sample_inputs/producer_consumer.txt
./bankers < sample_inputs/banker.txt
./first_fit < sample_inputs/memory.txt
./best_fit < sample_inputs/memory.txt
./worst_fit < sample_inputs/memory.txt
./fcfs_disk < sample_inputs/disk.txt
./sstf_disk < sample_inputs/disk.txt
./scan_disk < sample_inputs/disk.txt
./cscan_disk < sample_inputs/disk.txt
```

## Input formats

| Program | stdin |
|:---|:---|
| `fcfs` | `n`, then `arrival burst` × n |
| `sjf` | `n`, then `burst` × n |
| `priority` | `n`, then `burst priority` × n |
| `fifo/lru/optimal` | `frames`, `pages`, then reference string |
| `bankers` | `n m`, allocation matrix, max matrix, available vector |
| `producer_consumer` | `1 item` produce, `2` consume, `0` exit |
| `first_fit/best_fit/worst_fit` | `blocks processes`, block sizes, process sizes |
| disk programs | `n`, requests, initial head |

## Memory hooks

- **Unix**: `pwd`, `cd`, `mkdir -p`, `touch`, `cp`, `mv`, `rm`, `ls -l`, `cat`, `head`, `tail`, `chmod`, `ps`, `kill`, `df -h`, `du -sh`.
- **CPU**: `CT = max(prev CT, AT) + BT`, `TAT = CT - AT`, `WT = TAT - BT`.
- **Page replacement**: FIFO = circular pointer; LRU = smallest last-used time; Optimal = farthest next use (never used = last).
- **Banker's**: `Need = Max - Alloc`; run if `Need <= Available`; then `Available += Alloc`.
- **Memory**: First = first fit; Best = smallest sufficient; Worst = largest.
- **Disk**: FCFS = given order; SSTF = nearest; SCAN = to end then reverse; C-SCAN = to end, jump to 0, same direction.
