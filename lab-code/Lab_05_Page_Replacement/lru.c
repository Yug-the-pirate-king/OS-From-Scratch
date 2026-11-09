// Lab 5: LRU page replacement
// Input: frames, pages, reference string
#include <stdio.h>

int main() {
    int frames, n, i, j, time = 0, faults = 0;
    int ref[50], frame[10], used[10];

    scanf("%d%d", &frames, &n);
    for (i = 0; i < n; i++) scanf("%d", &ref[i]);
    for (i = 0; i < frames; i++) { frame[i] = -1; used[i] = 0; }

    for (i = 0; i < n; i++) {
        int hit = 0;
        for (j = 0; j < frames; j++)
            if (frame[j] == ref[i]) { used[j] = ++time; hit = 1; break; }
        if (!hit) {
            int pos = 0;
            for (j = 0; j < frames; j++)
                if (frame[j] == -1) { pos = j; break; }
            if (frame[pos] != -1)
                for (j = 1; j < frames; j++)
                    if (used[j] < used[pos]) pos = j;
            frame[pos] = ref[i];
            used[pos] = ++time;
            faults++;
        }
    }
    printf("Page Faults = %d\nHits = %d\n", faults, n - faults);
    return 0;
}
