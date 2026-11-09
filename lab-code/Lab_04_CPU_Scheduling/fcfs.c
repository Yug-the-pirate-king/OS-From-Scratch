// Lab 4: FCFS CPU scheduling
// Input: n, then n lines of arrival burst
#include <stdio.h>

typedef struct { int pid, at, bt, ct, tat, wt; } Process;

int main() {
    int n, i, j;
    Process p[20], t;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        scanf("%d%d", &p[i].at, &p[i].bt);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++)
            if (p[i].at > p[j].at) { t = p[i]; p[i] = p[j]; p[j] = t; }
    }

    float awt = 0, atat = 0;
    for (i = 0; i < n; i++) {
        if (i == 0 || p[i - 1].ct < p[i].at) p[i].ct = p[i].at + p[i].bt;
        else p[i].ct = p[i - 1].ct + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        awt += p[i].wt;
        atat += p[i].tat;
        printf("P%d AT=%d BT=%d CT=%d TAT=%d WT=%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Avg WT=%.2f Avg TAT=%.2f\n", awt / n, atat / n);
    return 0;
}
