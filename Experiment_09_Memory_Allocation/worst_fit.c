// Standalone Worst Fit Memory Allocation
#include <stdio.h>

int main() {
    int nb, np, i, j;
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter number of processes: ");
    scanf("%d", &np);

    int blocks[nb], processes[np], allocation[np];

    printf("Enter size of blocks:\n");
    for (i = 0; i < nb; i++) scanf("%d", &blocks[i]);

    printf("Enter size of processes:\n");
    for (i = 0; i < np; i++) {
        scanf("%d", &processes[i]);
        allocation[i] = -1;
    }

    for (i = 0; i < np; i++) {
        int worst_idx = -1;
        for (j = 0; j < nb; j++) {
            if (blocks[j] >= processes[i]) {
                if (worst_idx == -1 || blocks[j] > blocks[worst_idx]) {
                    worst_idx = j;
                }
            }
        }
        if (worst_idx != -1) {
            allocation[i] = worst_idx;
            blocks[worst_idx] -= processes[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}

