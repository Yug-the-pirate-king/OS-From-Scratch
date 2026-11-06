# Experiment 4: CPU Scheduling Algorithms (FCFS, SJF, Priority)

> **Author:** Yug Shah (TYCSE)  
> **Repository:** Os from scratch  
> **Course:** Operating Systems Lab  

## 1. Aim
To implement and analyze different CPU scheduling algorithms such as First Come First Serve (FCFS), Shortest Job First (SJF), and Priority Scheduling using C programming.

## 2. Course Outcome & Learning Objectives
- **Course Outcome:** Apply CPU scheduling algorithms.
- **Learning Objectives:**
  - Understand the concept and goals of process scheduling in multi-programmed operating systems.
  - Implement and trace the mechanics of non-preemptive FCFS, SJF, and Priority algorithms.
  - Calculate Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT).
  - Compare algorithm efficiency, throughput, and fairness.
  - Analyze edge conditions such as convoy effect and process starvation.

---

## 3. Related Theory & Core Metrics

### 3.1 Terminology & Standard Formulas
- **Arrival Time ($AT$):** The time instant at which a process enters the ready queue.
- **Burst Time ($BT$):** The execution duration required by a process on the CPU.
- **Completion Time ($CT$):** The time instant when the process completes its execution.
- **Turnaround Time ($TAT$):** Total elapsed time from process arrival to process termination:
  $$TAT = CT - AT$$
- **Waiting Time ($WT$):** Total duration spent by a process in the ready queue waiting for the CPU:
  $$WT = TAT - BT$$
- **Average Waiting Time ($AWT$):**
  $$AWT = \frac{1}{n} \sum_{i=1}^{n} WT_i$$
- **Average Turnaround Time ($ATAT$):**
  $$ATAT = \frac{1}{n} \sum_{i=1}^{n} TAT_i$$

---

### 3.2 Scheduling Algorithms

#### 1. First Come First Serve (FCFS)
- **Criterion:** Arrival Time ($AT$).
- **Mode:** Non-preemptive.
- **Description:** The process that arrives first is allocated the CPU first.
- **Advantage:** Simplest to understand and implement using a standard FIFO queue.
- **Disadvantage:** Suffer from the **Convoy Effect**, where small processes wait behind long CPU-bound processes, drastically inflating average waiting time.

#### 2. Shortest Job First (SJF)
- **Criterion:** Burst Time ($BT$).
- **Mode:** Non-preemptive (in this implementation).
- **Description:** The process with the smallest execution time is chosen first.
- **Advantage:** Mathematically optimal for minimizing average waiting time among non-preemptive algorithms.
- **Disadvantage:** May cause **starvation** (indefinite postponement) for longer jobs if short jobs continually enter the queue. Burst time cannot always be known in advance.

#### 3. Priority Scheduling
- **Criterion:** Priority value assigned to each process.
- **Convention:** Lower numerical value denotes higher priority (e.g., Priority 1 > Priority 3).
- **Mode:** Non-preemptive.
- **Advantage:** Allows critical real-time tasks to take precedence.
- **Disadvantage:** Lower-priority processes can suffer from starvation. Solved by **aging** (gradually increasing the priority of waiting processes over time).

---

## 4. Algorithms & Implementation Details

### FCFS Algorithm Flow
1. Input number of processes $n$, followed by $AT$ and $BT$ for each process.
2. Sort processes in ascending order of Arrival Time ($AT$).
3. For the first process: $CT[0] = AT[0] + BT[0]$.
4. For each subsequent process $i$:
   - If $CT[i-1] < AT[i]$, CPU is idle during this interval &rarr; $CT[i] = AT[i] + BT[i]$.
   - Else $CT[i] = CT[i-1] + BT[i]$.
5. Compute $TAT[i] = CT[i] - AT[i]$ and $WT[i] = TAT[i] - BT[i]$.
6. Sum and divide by $n$ to compute average waiting time and turnaround time.

---

## 5. Compilation and Execution

### Compiling with GCC
```bash
# Compile FCFS
gcc -Wall -o fcfs fcfs.c

# Compile SJF
gcc -Wall -o sjf sjf.c

# Compile Priority Scheduling
gcc -Wall -o priority priority.c
```

### Running the Programs
```bash
./fcfs
./sjf
./priority
```

---

## 6. Sample Inputs & Expected Outputs (from Lab Manual)

### 6.1 FCFS Output
```text
Enter number of processes: 3
Enter Arrival Time and Burst Time:
P1 Arrival Time: 0
P1 Burst Time: 5
P2 Arrival Time: 2
P2 Burst Time: 6
P3 Arrival Time: 3
P3 Burst Time: 10

P	AT	BT	CT	TAT	WT
P1	0	5	5	5	0
P2	2	6	11	9	3
P3	3	10	21	18	8

Average Waiting Time = 3.67
Average Turnaround Time = 10.67
```

### 6.2 SJF Output
```text
Enter number of processes: 3
Enter Burst Time:
P1: 5
P2: 8
P3: 2

P	BT	WT	TAT
P3	2	0	2
P1	5	2	7
P2	8	7	15

Average Waiting Time = 3.00
Average Turnaround Time = 8.00
```

### 6.3 Priority Scheduling Output
```text
Enter number of processes: 3
Enter Burst Time for P1: 9
Enter Priority for P1: 3
Enter Burst Time for P2: 5
Enter Priority for P2: 1
Enter Burst Time for P3: 7
Enter Priority for P3: 2

PID	BT	PR	WT	TAT
P2	5	1	0	5
P3	7	2	5	12
P1	9	3	12	21

Average Waiting Time = 5.67
Average Turnaround Time = 12.67
```

---

## 7. Viva Voce & Interview Questions with Answers

### Q1: What is the Convoy Effect in FCFS scheduling?
**Answer:**
The Convoy Effect occurs when a long, CPU-intensive process occupies the CPU for an extended duration while many shorter I/O-bound processes sit idle in the ready queue waiting for their turn. This leads to poor CPU and device utilization and significantly increases average waiting time.

### Q2: Why is SJF considered optimal?
**Answer:**
SJF is optimal because scheduling a shorter process before a longer process reduces the waiting time for the shorter process by more than it increases the waiting time for the longer process. Consequently, the average waiting time across all processes is minimized.

### Q3: What is the primary disadvantage of SJF and Priority scheduling? How is it resolved?
**Answer:**
The main disadvantage is **starvation** (indefinite blocking), where low-priority or long burst-time processes may never get CPU time if high-priority or shorter processes continue to arrive. It is resolved using **Aging**, a technique that gradually increments the priority of processes waiting in the ready queue for a prolonged period.

### Q4: What is the difference between preemptive and non-preemptive scheduling?
**Answer:**
- **Non-preemptive:** Once the CPU has been allocated to a process, the process retains control until it terminates or switches to the waiting state (e.g., I/O block).
- **Preemptive:** The operating system can interrupt and de-allocate a running process when a higher-priority process arrives or when its allocated time slice expires (e.g., Round Robin, SRTF).

### Q5: Can the waiting time of a process ever be negative?
**Answer:**
No. Waiting time is defined as $WT = TAT - BT$. Since $TAT = CT - AT$, and $CT \ge AT + BT$, it follows that $WT \ge 0$. A negative waiting time indicates an error in calculation.

---

## 8. Conclusion
The experiment demonstrated the practical implementation and performance differences between FCFS, SJF, and Priority CPU scheduling algorithms. Analysis of the results confirms that SJF achieves the lowest average waiting time, while Priority scheduling allows execution precedence based on task urgency.

