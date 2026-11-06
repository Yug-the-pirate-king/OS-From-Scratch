// ==============================================================================
// Experiment 08: Banker's Deadlock Avoidance Algorithm
// Determines system safety and generates Safe Execution Sequence
// ==============================================================================

#include <stdio.h>

int main() {
    int n, m, i, j;

    printf("===================================================\n");
    printf("        BANKER'S DEADLOCK AVOIDANCE ALGORITHM       \n");
    printf("===================================================\n");

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid process count.\n");
        return 1;
    }

    printf("Enter number of resources: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Invalid resource count.\n");
        return 1;
    }

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Max Matrix
    printf("\nEnter Max Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources (%d values):\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix = Max - Allocation
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Display calculated Need Matrix
    printf("\n--- Calculated Need Matrix ---\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int count = 0;

    // Safety Algorithm
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int safe_flag = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        safe_flag = 0;
                        break;
                    }
                }

                // If all resource needs can be satisfied
                if (safe_flag) {
                    for (j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process could be safely allocated, system is not in a safe state
        if (found == 0) {
            break;
        }
    }

    // Output Result
    printf("\n===================================================\n");
    if (count == n) {
        printf("RESULT: System is in a SAFE STATE.\n");
        printf("Safe Sequence: ");
        for (i = 0; i < n; i++) {
            printf("P%d ", safe[i]);
        }
        printf("\n");
    } else {
        printf("RESULT: System is NOT in a safe state (Deadlock potential detected).\n");
    }
    printf("===================================================\n");

    return 0;
}

