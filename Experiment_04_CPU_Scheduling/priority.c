// ==============================================================================
// Experiment 04: Priority CPU Scheduling Algorithm (Non-preemptive)
// Note: Lower numerical priority value indicates higher scheduling priority.
// ==============================================================================

#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    int bt[n], pr[n], wt[n], tat[n], pid[n];

    // Input burst times and priorities
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
        printf("Enter Priority for P%d: ", pid[i]);
        scanf("%d", &pr[i]);
    }

    // Sorting based on priority (lower value = higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                // Swap priority
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate Turnaround Time
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output table
    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], bt[i], pr[i], wt[i], tat[i]);
    }

    // Average calculations
    float total_wt = 0, total_tat = 0;
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

