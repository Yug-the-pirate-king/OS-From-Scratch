// Lab 9: First Fit memory allocation
// Input: blocks processes, block sizes, process sizes
#include <stdio.h>

int main() {
    int nb, np, i, j;
    int block[20], process[20], alloc[20];

    scanf("%d%d", &nb, &np);
    for (i = 0; i < nb; i++) scanf("%d", &block[i]);
    for (i = 0; i < np; i++) { scanf("%d", &process[i]); alloc[i] = -1; }

    for (i = 0; i < np; i++)
        for (j = 0; j < nb; j++)
            if (block[j] >= process[i]) {
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }

    for (i = 0; i < np; i++) {
        if (alloc[i] == -1) printf("P%d -> Not Allocated\n", i + 1);
        else printf("P%d -> Block %d\n", i + 1, alloc[i] + 1);
    }
    return 0;
}
