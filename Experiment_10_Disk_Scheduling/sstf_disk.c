// ==============================================================================
// Experiment 10: SSTF (Shortest Seek Time First) Disk Scheduling Algorithm
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], visited[20] = {0};
    int n, head, i, j, seek = 0;

    printf("===================================================\n");
    printf("         SSTF DISK SCHEDULING ALGORITHM            \n");
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
        int min = 9999, index = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(req[j] - head);
                if (dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }
        visited[index] = 1;
        seek += min;
        head = req[index];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time (SSTF): %d\n", seek);
    printf("Average Seek Time: %.2f\n", (float)seek / n);
    return 0;
}

