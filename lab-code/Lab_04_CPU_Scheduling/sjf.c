// Lab 4: SJF CPU scheduling (non-preemptive)
// Input: n, then n burst times
#include <stdio.h>

typedef struct { int pid, bt, wt, tat; } Process;

int main() {
    int n, i, j;
    Process p[20], t;

    scanf("%d", &n);
    for (i = 0; i < n; i++) { p[i].pid = i + 1; scanf("%d", &p[i].bt); }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].bt > p[j].bt) { t = p[i]; p[i] = p[j]; p[j] = t; }

    float twt = 0, ttat = 0;
    for (i = 0; i < n; i++) {
        p[i].wt = (i == 0 ? 0 : p[i - 1].wt + p[i - 1].bt);
        p[i].tat = p[i].wt + p[i].bt;
        twt += p[i].wt;
        ttat += p[i].tat;
        printf("P%d BT=%d WT=%d TAT=%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }
    printf("Avg WT=%.2f Avg TAT=%.2f\n", twt / n, ttat / n);
    return 0;
}
