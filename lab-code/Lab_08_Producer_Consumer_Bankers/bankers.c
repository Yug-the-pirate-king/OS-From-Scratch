// Lab 8: Banker's deadlock avoidance
// Input: n m, allocation matrix, max matrix, available vector
#include <stdio.h>

int main() {
    int n, m, i, j, k = 0;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) scanf("%d", &alloc[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) scanf("%d", &max[i][j]);
    for (j = 0; j < m; j++) scanf("%d", &avail[j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) need[i][j] = max[i][j] - alloc[i][j];

    int found;
    do {
        found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i]) continue;
            int can = 1;
            for (j = 0; j < m && can; j++)
                if (need[i][j] > avail[j]) can = 0;
            if (can) {
                for (j = 0; j < m; j++) avail[j] += alloc[i][j];
                finish[i] = 1;
                safe[k++] = i;
                found = 1;
            }
        }
    } while (found);

    if (k == n) {
        printf("Safe sequence: ");
        for (i = 0; i < n; i++) printf("P%d ", safe[i]);
        printf("\n");
    } else {
        printf("Unsafe state\n");
    }
    return 0;
}
