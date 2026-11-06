// ==============================================================================
// Experiment 10: C-SCAN (Circular SCAN) Disk Scheduling Algorithm
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], n, head, size = 200;
    int i, j, seek = 0;

    printf("===================================================\n");
    printf("        C-SCAN (CIRCULAR SCAN) DISK SCHEDULING      \n");
    printf("===================================================\n");

    printf("Enter number of requests: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 20) {
        printf("Invalid request count.\n");
        return 1;
    }

    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort requests in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    // Find partition index where request > head
    int pos = n;
    for (i = 0; i < n; i++) {
        if (req[i] > head) {
            pos = i;
            break;
        }
    }

    printf("\nHead Movement Sequence:\n%d", head);

    // Phase 1: Move right servicing requests greater than head
    for (i = pos; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    // Reach highest cylinder (size - 1)
    seek += abs((size - 1) - head);
    head = size - 1;
    printf(" -> %d [End]", head);

    // Circular jump to cylinder 0 without servicing requests
    seek += (size - 1);
    head = 0;
    printf(" -> %d [Jump to Start]", head);

    // Phase 2: Move right again servicing requests from cylinder 0 up to pos
    for (i = 0; i < pos; i++) {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time (C-SCAN): %d\n", seek);
    printf("Average Seek Time: %.2f\n", (float)seek / n);
    return 0;
}

