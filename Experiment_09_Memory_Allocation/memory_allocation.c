// ==============================================================================
// Experiment 09: Dynamic Memory Allocation Simulation
// Demonstrates First Fit, Best Fit, and Worst Fit Strategies
// ==============================================================================

#include <stdio.h>

int main() {
    int blocks[10], processes[10];
    int i, j, nb, np;

    printf("===================================================\n");
    printf("    MEMORY ALLOCATION: FIRST FIT, BEST FIT, WORST FIT \n");
    printf("===================================================\n");

    printf("Enter number of memory blocks: ");
    if (scanf("%d", &nb) != 1 || nb <= 0 || nb > 10) {
        printf("Invalid block count.\n");
        return 1;
    }

    printf("Enter number of processes: ");
    if (scanf("%d", &np) != 1 || np <= 0 || np > 10) {
        printf("Invalid process count.\n");
        return 1;
    }

    printf("Enter size of blocks:\n");
    for (i = 0; i < nb; i++) {
        scanf("%d", &blocks[i]);
    }

    printf("Enter size of processes:\n");
    for (i = 0; i < np; i++) {
        scanf("%d", &processes[i]);
    }

    // -------------------------------------------------------------
    // 1. FIRST FIT
    // -------------------------------------------------------------
    printf("\n--- First Fit ---\n");
    int temp[10];
    for (i = 0; i < nb; i++) {
        temp[i] = blocks[i];
    }

    for (i = 0; i < np; i++) {
        int allocated = 0;
        for (j = 0; j < nb; j++) {
            if (temp[j] >= processes[i]) {
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                temp[j] -= processes[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("Process %d Not Allocated\n", i + 1);
        }
    }

    // -------------------------------------------------------------
    // 2. BEST FIT
    // -------------------------------------------------------------
    printf("\n--- Best Fit ---\n");
    for (i = 0; i < nb; i++) {
        temp[i] = blocks[i];
    }

    for (i = 0; i < np; i++) {
        int best = -1;
        for (j = 0; j < nb; j++) {
            if (temp[j] >= processes[i]) {
                if (best == -1 || temp[j] < temp[best]) {
                    best = j;
                }
            }
        }

        if (best != -1) {
            printf("Process %d allocated to Block %d\n", i + 1, best + 1);
            temp[best] -= processes[i];
        } else {
            printf("Process %d Not Allocated\n", i + 1);
        }
    }

    // -------------------------------------------------------------
    // 3. WORST FIT
    // -------------------------------------------------------------
    printf("\n--- Worst Fit ---\n");
    for (i = 0; i < nb; i++) {
        temp[i] = blocks[i];
    }

    for (i = 0; i < np; i++) {
        int worst = -1;
        for (j = 0; j < nb; j++) {
            if (temp[j] >= processes[i]) {
                if (worst == -1 || temp[j] > temp[worst]) {
                    worst = j;
                }
            }
        }

        if (worst != -1) {
            printf("Process %d allocated to Block %d\n", i + 1, worst + 1);
            temp[worst] -= processes[i];
        } else {
            printf("Process %d Not Allocated\n", i + 1);
        }
    }

    return 0;
}

