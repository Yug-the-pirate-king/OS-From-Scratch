// ==============================================================================
// Experiment 04: Shortest Job First (SJF) CPU Scheduling Algorithm (Non-preemptive)
// ==============================================================================

#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    int pid[n], bt[n], wt[n], tat[n];

    // Input burst times
    printf("Enter Burst Time:\n");
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Sort by burst time (SJF)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Display results
    float total_wt = 0, total_tat = 0;
    printf("\nP\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

