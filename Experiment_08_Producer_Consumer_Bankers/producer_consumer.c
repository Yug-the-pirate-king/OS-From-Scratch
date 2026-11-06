// ==============================================================================
// Experiment 08: Producer - Consumer Problem (Bounded Buffer Simulation)
// ==============================================================================

#include <stdio.h>

#define BUFFER_SIZE 5

int main() {
    int buffer[BUFFER_SIZE];
    int in = 0, out = 0;
    int choice, item, count = 0;

    printf("===================================================\n");
    printf("    PRODUCER - CONSUMER PROBLEM SIMULATION         \n");
    printf("    Buffer Capacity: %d items                      \n", BUFFER_SIZE);
    printf("===================================================\n");

    while (1) {
        printf("\n1. Produce   2. Consume   3. Exit");
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                if (count == BUFFER_SIZE) {
                    printf("Buffer is Full! Cannot produce item.\n");
                } else {
                    printf("Enter item: ");
                    scanf("%d", &item);
                    buffer[in] = item;
                    in = (in + 1) % BUFFER_SIZE;
                    count++;
                    printf("Produced: %d (Buffer Count: %d/%d)\n", item, count, BUFFER_SIZE);
                }
                break;

            case 2:
                if (count == 0) {
                    printf("Buffer is Empty! Cannot consume item.\n");
                } else {
                    item = buffer[out];
                    out = (out + 1) % BUFFER_SIZE;
                    count--;
                    printf("Consumed: %d (Buffer Count: %d/%d)\n", item, count, BUFFER_SIZE);
                }
                break;

            case 3:
                printf("Exiting Producer-Consumer simulation.\n");
                return 0;

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}

