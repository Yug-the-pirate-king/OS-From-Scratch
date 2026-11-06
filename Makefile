# ==============================================================================
# Os from scratch - Makefile
# Author: Yug Shah (TYCSE)
# Description: Automated build and test script for OS Lab implementations
# ==============================================================================

CC = gcc
CFLAGS = -Wall -Wextra -O2
PTHREAD_FLAGS = -pthread

.PHONY: all clean test help

all: exp4 exp5 exp6 exp7 exp8 exp9 exp10
	@echo "=========================================================="
	@echo " All OS experiments compiled successfully by Yug Shah (TYCSE)"
	@echo " Repository: Os from scratch"
	@echo "=========================================================="

exp4:
	$(CC) $(CFLAGS) Experiment_04_CPU_Scheduling/fcfs.c -o Experiment_04_CPU_Scheduling/fcfs
	$(CC) $(CFLAGS) Experiment_04_CPU_Scheduling/sjf.c -o Experiment_04_CPU_Scheduling/sjf
	$(CC) $(CFLAGS) Experiment_04_CPU_Scheduling/priority.c -o Experiment_04_CPU_Scheduling/priority

exp5:
	$(CC) $(CFLAGS) Experiment_05_Page_Replacement/fifo.c -o Experiment_05_Page_Replacement/fifo
	$(CC) $(CFLAGS) Experiment_05_Page_Replacement/optimal.c -o Experiment_05_Page_Replacement/optimal
	$(CC) $(CFLAGS) Experiment_05_Page_Replacement/lru.c -o Experiment_05_Page_Replacement/lru

exp6:
	$(CC) $(CFLAGS) Experiment_06_Concurrency_Processes_Threads/fork_vfork.c -o Experiment_06_Concurrency_Processes_Threads/fork_vfork
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) Experiment_06_Concurrency_Processes_Threads/pthread_demo.c -o Experiment_06_Concurrency_Processes_Threads/pthread_demo

exp7:
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) Experiment_07_Process_Synchronization/sync_primitives.c -o Experiment_07_Process_Synchronization/sync_primitives

exp8:
	$(CC) $(CFLAGS) Experiment_08_Producer_Consumer_Bankers/producer_consumer.c -o Experiment_08_Producer_Consumer_Bankers/producer_consumer
	$(CC) $(CFLAGS) Experiment_08_Producer_Consumer_Bankers/bankers_algorithm.c -o Experiment_08_Producer_Consumer_Bankers/bankers_algorithm

exp9:
	$(CC) $(CFLAGS) Experiment_09_Memory_Allocation/memory_allocation.c -o Experiment_09_Memory_Allocation/memory_allocation
	$(CC) $(CFLAGS) Experiment_09_Memory_Allocation/first_fit.c -o Experiment_09_Memory_Allocation/first_fit
	$(CC) $(CFLAGS) Experiment_09_Memory_Allocation/best_fit.c -o Experiment_09_Memory_Allocation/best_fit
	$(CC) $(CFLAGS) Experiment_09_Memory_Allocation/worst_fit.c -o Experiment_09_Memory_Allocation/worst_fit

exp10:
	$(CC) $(CFLAGS) Experiment_10_Disk_Scheduling/fcfs_disk.c -o Experiment_10_Disk_Scheduling/fcfs_disk
	$(CC) $(CFLAGS) Experiment_10_Disk_Scheduling/sstf_disk.c -o Experiment_10_Disk_Scheduling/sstf_disk
	$(CC) $(CFLAGS) Experiment_10_Disk_Scheduling/scan_disk.c -o Experiment_10_Disk_Scheduling/scan_disk
	$(CC) $(CFLAGS) Experiment_10_Disk_Scheduling/cscan_disk.c -o Experiment_10_Disk_Scheduling/cscan_disk

clean:
	rm -f Experiment_04_CPU_Scheduling/fcfs Experiment_04_CPU_Scheduling/sjf Experiment_04_CPU_Scheduling/priority
	rm -f Experiment_05_Page_Replacement/fifo Experiment_05_Page_Replacement/optimal Experiment_05_Page_Replacement/lru
	rm -f Experiment_06_Concurrency_Processes_Threads/fork_vfork Experiment_06_Concurrency_Processes_Threads/pthread_demo
	rm -f Experiment_07_Process_Synchronization/sync_primitives
	rm -f Experiment_08_Producer_Consumer_Bankers/producer_consumer Experiment_08_Producer_Consumer_Bankers/bankers_algorithm
	rm -f Experiment_09_Memory_Allocation/memory_allocation Experiment_09_Memory_Allocation/first_fit Experiment_09_Memory_Allocation/best_fit Experiment_09_Memory_Allocation/worst_fit
	rm -f Experiment_10_Disk_Scheduling/fcfs_disk Experiment_10_Disk_Scheduling/sstf_disk Experiment_10_Disk_Scheduling/scan_disk Experiment_10_Disk_Scheduling/cscan_disk
	@echo "Clean completed."

help:
	@echo "Os from scratch - Build targets:"
	@echo "  make all   : Compiles all experiments"
	@echo "  make exp4  : Compiles CPU Scheduling"
	@echo "  make exp5  : Compiles Page Replacement"
	@echo "  make exp6  : Compiles Concurrency (fork, pthread)"
	@echo "  make exp7  : Compiles Synchronization (mutex, semaphore)"
	@echo "  make exp8  : Compiles Producer-Consumer & Banker's"
	@echo "  make exp9  : Compiles Dynamic Memory Allocation"
	@echo "  make exp10 : Compiles Disk Scheduling"
	@echo "  make clean : Deletes compiled executables"

