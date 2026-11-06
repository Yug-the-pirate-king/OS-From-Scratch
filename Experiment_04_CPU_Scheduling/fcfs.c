// ==============================================================================
// Experiment 04: First Come First Serve (FCFS) CPU Scheduling Algorithm
// ==============================================================================

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    int pid[n], at[n], bt[n], wt[n], tat[n], ct[n];

    // Input arrival time and burst time
    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sorting processes based on arrival time (FCFS rule)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

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

    // First process completion time
    ct[0] = at[0] + bt[0];

    // Calculate completion time
    for (int i = 1; i < n; i++) {
        if (ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i]; // CPU idle case
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    // Calculate Turnaround Time (TAT) and Waiting Time (WT)
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    float total_wt = 0, total_tat = 0;
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

