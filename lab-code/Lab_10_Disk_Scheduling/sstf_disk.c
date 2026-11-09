// Lab 10: SSTF disk scheduling
// Input: n, requests, initial head
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, seek = 0;
    int req[20], done[20] = {0};

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &req[i]);
    scanf("%d", &head);

    printf("%d", head);
    for (i = 0; i < n; i++) {
        int min = 9999, pos = -1;
        for (j = 0; j < n; j++)
            if (!done[j] && abs(req[j] - head) < min) {
                min = abs(req[j] - head);
                pos = j;
            }
        seek += min;
        head = req[pos];
        done[pos] = 1;
        printf(" -> %d", head);
    }
    printf("\nSeek = %d\n", seek);
    return 0;
}
