CC = gcc
CFLAGS = -Wall -O2

PROGS = fcfs sjf priority fifo lru optimal fork_vfork pthread_demo \
        sync_primitives producer_consumer bankers first_fit best_fit \
        worst_fit fcfs_disk sstf_disk scan_disk cscan_disk

all: $(PROGS)

fcfs: Lab_04_CPU_Scheduling/fcfs.c
	$(CC) $(CFLAGS) -o $@ $<

sjf: Lab_04_CPU_Scheduling/sjf.c
	$(CC) $(CFLAGS) -o $@ $<

priority: Lab_04_CPU_Scheduling/priority.c
	$(CC) $(CFLAGS) -o $@ $<

fifo: Lab_05_Page_Replacement/fifo.c
	$(CC) $(CFLAGS) -o $@ $<

lru: Lab_05_Page_Replacement/lru.c
	$(CC) $(CFLAGS) -o $@ $<

optimal: Lab_05_Page_Replacement/optimal.c
	$(CC) $(CFLAGS) -o $@ $<

fork_vfork: Lab_06_Concurrency/fork_vfork.c
	$(CC) $(CFLAGS) -o $@ $<

pthread_demo: Lab_06_Concurrency/pthread_demo.c
	$(CC) $(CFLAGS) -pthread -o $@ $<

sync_primitives: Lab_07_Synchronization/sync_primitives.c
	$(CC) $(CFLAGS) -pthread -o $@ $<

producer_consumer: Lab_08_Producer_Consumer_Bankers/producer_consumer.c
	$(CC) $(CFLAGS) -o $@ $<

bankers: Lab_08_Producer_Consumer_Bankers/bankers.c
	$(CC) $(CFLAGS) -o $@ $<

first_fit: Lab_09_Memory_Allocation/first_fit.c
	$(CC) $(CFLAGS) -o $@ $<

best_fit: Lab_09_Memory_Allocation/best_fit.c
	$(CC) $(CFLAGS) -o $@ $<

worst_fit: Lab_09_Memory_Allocation/worst_fit.c
	$(CC) $(CFLAGS) -o $@ $<

fcfs_disk: Lab_10_Disk_Scheduling/fcfs_disk.c
	$(CC) $(CFLAGS) -o $@ $<

sstf_disk: Lab_10_Disk_Scheduling/sstf_disk.c
	$(CC) $(CFLAGS) -o $@ $<

scan_disk: Lab_10_Disk_Scheduling/scan_disk.c
	$(CC) $(CFLAGS) -o $@ $<

cscan_disk: Lab_10_Disk_Scheduling/cscan_disk.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS) *.exe

.PHONY: all clean
