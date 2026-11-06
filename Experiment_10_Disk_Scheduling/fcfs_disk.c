// ==============================================================================
// Experiment 10: FCFS (First Come First Serve) Disk Scheduling Algorithm
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], n, head, i, seek = 0;

    printf("===================================================\n");
    printf("         FCFS DISK SCHEDULING ALGORITHM            \n");
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

    printf("\nHead Movement Sequence:\n%d", head);
    for (i = 0; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time (FCFS): %d\n", seek);
    printf("Average Seek Time: %.2f\n", (float)seek / n);
    return 0;
}

