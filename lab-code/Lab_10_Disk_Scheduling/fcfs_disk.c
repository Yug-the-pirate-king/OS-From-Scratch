// Lab 10: FCFS disk scheduling
// Input: n, requests, initial head
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, seek = 0, req[20];

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &req[i]);
    scanf("%d", &head);

    printf("%d", head);
    for (i = 0; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\nSeek = %d\n", seek);
    return 0;
}
