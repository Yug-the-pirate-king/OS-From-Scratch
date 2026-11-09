// Lab 5: Optimal page replacement
// Input: frames, pages, reference string
#include <stdio.h>

int main() {
    int frames, n, i, j, k, faults = 0;
    int ref[50], frame[10];

    scanf("%d%d", &frames, &n);
    for (i = 0; i < n; i++) scanf("%d", &ref[i]);
    for (i = 0; i < frames; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        int hit = 0;
        for (j = 0; j < frames; j++)
            if (frame[j] == ref[i]) { hit = 1; break; }
        if (!hit) {
            int pos = 0, farthest = -1;
            for (j = 0; j < frames; j++) {
                int next = n;
                for (k = i + 1; k < n; k++)
                    if (frame[j] == ref[k]) { next = k; break; }
                if (next > farthest) { farthest = next; pos = j; }
            }
            frame[pos] = ref[i];
            faults++;
        }
    }
    printf("Page Faults = %d\nHits = %d\n", faults, n - faults);
    return 0;
}
