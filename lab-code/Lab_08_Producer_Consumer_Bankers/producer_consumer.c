// Lab 8: Producer-Consumer bounded buffer
// Input: choice (1 produce, 2 consume, 0 exit), item when producing
#include <stdio.h>
#define N 5

int main() {
    int buffer[N], in = 0, out = 0, count = 0, choice, item;

    while (1) {
        printf("1.Produce 2.Consume 0.Exit: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice == 1) {
            if (count == N) {
                printf("Buffer full\n");
            } else {
                printf("Item: ");
                scanf("%d", &item);
                buffer[in] = item;
                in = (in + 1) % N;
                count++;
                printf("Produced %d\n", item);
            }
        } else if (choice == 2) {
            if (count == 0) {
                printf("Buffer empty\n");
            } else {
                printf("Consumed %d\n", buffer[out]);
                out = (out + 1) % N;
                count--;
            }
        }
    }
    return 0;
}
