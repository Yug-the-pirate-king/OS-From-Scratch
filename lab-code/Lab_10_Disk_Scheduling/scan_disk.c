// Lab 10: SCAN (elevator) disk scheduling, disk size 200
// Input: n, requests, initial head
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, seek = 0, size = 200;
    int req[20];

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &req[i]);
    scanf("%d", &head);

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (req[j] > req[j + 1]) {
                int t = req[j];
                req[j] = req[j + 1];
                req[j + 1] = t;
            }

    int pos = 0;
    while (pos < n && req[pos] <= head) pos++;

    printf("%d", head);
    for (i = pos; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }
    if (head != size - 1) {
        seek += abs((size - 1) - head);
        head = size - 1;
        printf(" -> %d", head);
    }

    for (i = pos - 1; i >= 0; i--) {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\nSeek = %d\n", seek);
    return 0;
}
