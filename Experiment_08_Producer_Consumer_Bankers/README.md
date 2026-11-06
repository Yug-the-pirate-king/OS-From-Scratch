# Experiment 8: Producer-Consumer Problem and Banker's Algorithm

> **Author:** Yug Shah (TYCSE)  
> **Repository:** Os from scratch  
> **Course:** Operating Systems Lab  

## 1. Aim
To implement and understand the Producer-Consumer Problem and Banker's Algorithm using C programming.

## 2. Course Outcome & Learning Objectives
- **Course Outcome (CO):** Implement process synchronization techniques, and analyze deadlock conditions with appropriate prevention, avoidance, and recovery strategies.
- **Learning Objectives:**
  - Understand the concept and challenges of cooperating processes.
  - Model a bounded buffer for producer-consumer synchronization.
  - Understand deadlock characterization and the distinction between deadlock prevention, avoidance, and detection.
  - Implement Banker's Algorithm for deadlock avoidance.
  - Construct and evaluate system safety matrices ($Max$, $Allocation$, $Need$, and $Available$).

---

## 3. Related Theory

### 3.1 Producer-Consumer (Bounded-Buffer) Problem
In the Producer-Consumer problem, two processes share a common, fixed-size buffer:
- **Producer:** Generates data items and places them into the buffer. If the buffer is full, the producer must wait.
- **Consumer:** Extracts data items from the buffer. If the buffer is empty, the consumer must wait.

**Buffer Mechanics:**
- Implemented as a circular array of size $N$:
  $$\text{in} = (\text{in} + 1) \pmod N$$
  $$\text{out} = (\text{out} + 1) \pmod N$$
- A shared counter tracks the current occupancy:
  - Full Condition: $\text{count} == N$
  - Empty Condition: $\text{count} == 0$

---

### 3.2 Banker's Algorithm for Deadlock Avoidance
Named by Edsger Dijkstra, the Banker's algorithm is a deadlock avoidance strategy modeled on a small-town banker who never allocates cash such that he cannot satisfy the maximum cash needs of all his customers.

#### Data Structures (for $n$ processes and $m$ resource types)
1. **$Available[m]$:** Vector indicating the number of available instances of each resource type.
2. **$Max[n][m]$:** Matrix defining the maximum claim of each process.
3. **$Allocation[n][m]$:** Matrix defining the number of resources of each type currently allocated to each process.
4. **$Need[n][m]$:** Matrix indicating the remaining resource need of each process:
   $$Need[i][j] = Max[i][j] - Allocation[i][j]$$

#### Safety Algorithm Steps
1. Initialize two vectors:
   - $Work = Available$ (copy of available vector)
   - $Finish[i] = \text{false}$ for $i = 0, 1, \dots, n-1$
2. Find an index $i$ such that:
   - $Finish[i] == \text{false}$
   - $Need[i][j] \le Work[j]$ for all $j \in \{0, \dots, m-1\}$
   - If no such $i$ exists, proceed to Step 4.
3. Once satisfied:
   - $Work = Work + Allocation[i]$
   - $Finish[i] = \text{true}$
   - Append process $P_i$ to the safe sequence list.
   - Go back to Step 2.
4. If $Finish[i] == \text{true}$ for all $i$, then the system is in a **Safe State**; otherwise, the system is in an **Unsafe State** (risk of deadlock).

---

## 4. Source Files

| File | Description |
| :--- | :--- |
| `producer_consumer.c` | Interactive bounded-buffer simulation (Buffer size = 5) with full/empty detection. |
| `bankers_algorithm.c` | Full implementation of Banker's safety algorithm, printing Need matrix and safe sequence. |

---

## 5. How to Compile and Run

### Compiling
```bash
gcc -Wall -o producer_consumer producer_consumer.c
gcc -Wall -o bankers_algorithm bankers_algorithm.c
```

### Running
```bash
./producer_consumer
./bankers_algorithm
```

---

## 6. Sample Inputs and Outputs (from Lab Manual)

### 6.1 Producer-Consumer Run
```text
===================================================
    PRODUCER - CONSUMER PROBLEM SIMULATION         
    Buffer Capacity: 5 items                      
===================================================

1. Produce   2. Consume   3. Exit
Enter choice: 1
Enter item: 5
Produced: 5 (Buffer Count: 1/5)

1. Produce   2. Consume   3. Exit
Enter choice: 1
Enter item: 6
Produced: 6 (Buffer Count: 2/5)

1. Produce   2. Consume   3. Exit
Enter choice: 2
Consumed: 5 (Buffer Count: 1/5)

1. Produce   2. Consume   3. Exit
Enter choice: 3
Exiting Producer-Consumer simulation.
```

### 6.2 Banker's Algorithm Run
**Input Data:**
- Number of processes: `5`
- Number of resources: `3`
- Allocation Matrix:
  ```text
  1 1 2
  2 1 2
  4 0 1
  0 2 0
  1 1 2
  ```
- Max Matrix:
  ```text
  4 3 3
  3 2 2
  9 0 2
  7 5 3
  1 1 2
  ```
- Available Resources:
  ```text
  2 1 0
  ```

**Program Output:**
```text
--- Calculated Need Matrix ---
P0: 3 2 1 
P1: 1 1 0 
P2: 5 0 1 
P3: 7 3 3 
P4: 0 0 0 

===================================================
RESULT: System is in a SAFE STATE.
Safe Sequence: P1 P4 P0 P2 P3 
===================================================
```

---

## 7. Viva Voce & Interview Questions with Answers

### Q1: What is the difference between a Safe State and an Unsafe State?
**Answer:**
- A **Safe State** is one where there exists at least one safe execution sequence of processes such that all processes can obtain their maximum required resources without deadlocking.
- An **Unsafe State** is NOT necessarily a deadlock; however, an unsafe state may lead to a deadlock if processes request their maximum claims concurrently. Deadlock is a subset of unsafe states.

### Q2: What are the main disadvantages of Banker's Algorithm?
**Answer:**
1. It requires processes to declare their maximum resource demands in advance, which is rarely known in real dynamic environments.
2. The number of processes and resource types must remain fixed during execution.
3. Processes must guarantee to release all resources within a finite time.
4. High computation overhead ($O(m \cdot n^2)$).

### Q3: What is the difference between Deadlock Prevention and Deadlock Avoidance?
**Answer:**
- **Deadlock Prevention:** Imposes static constraints on resource requests to invalidate at least one of the four Coffman conditions (e.g., banning hold-and-wait, enforcing linear resource ordering).
- **Deadlock Avoidance:** Dynamically inspects every resource allocation request (using algorithms like Banker's) to verify that granting it will leave the system in a safe state.

### Q4: In the Producer-Consumer problem, what is the role of the shared counter?
**Answer:**
The shared counter tracks the net number of items currently present in the bounded buffer. It signals the producer to stop producing when $\text{count} == \text{BUFFER\_SIZE}$, and signals the consumer to stop consuming when $\text{count} == 0$.

---

## 8. Conclusion
The experiment illustrated how the Producer-Consumer model manages shared storage buffers between asynchronous cooperating processes, and how the Banker's Algorithm dynamically avoids deadlocks by verifying system safety before granting resource requests.

