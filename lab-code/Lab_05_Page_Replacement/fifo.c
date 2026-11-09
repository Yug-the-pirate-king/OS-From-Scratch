// Lab 5: FIFO page replacement
// Input: frames, pages, reference string
#include <stdio.h>

int main() {
    int frames, n, i, j, next = 0, faults = 0;
    int ref[50], frame[10];

    scanf("%d%d", &frames, &n);
    for (i = 0; i < n; i++) scanf("%d", &ref[i]);
    for (i = 0; i < frames; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        int hit = 0;
        for (j = 0; j < frames; j++)
            if (frame[j] == ref[i]) { hit = 1; break; }
        if (!hit) {
            frame[next] = ref[i];
            next = (next + 1) % frames;
            faults++;
        }
    }
    printf("Page Faults = %d\nHits = %d\n", faults, n - faults);
    return 0;
}
