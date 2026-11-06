// ==============================================================================
// Experiment 05: FIFO (First In First Out) Page Replacement Algorithm
// ==============================================================================

#include <stdio.h>

int main() {
    int frames, pages, i, j, index = 0, faults = 0;

    printf("Enter number of frames: ");
    if (scanf("%d", &frames) != 1 || frames <= 0) {
        printf("Invalid frame count.\n");
        return 1;
    }

    printf("Enter number of pages: ");
    if (scanf("%d", &pages) != 1 || pages <= 0) {
        printf("Invalid page count.\n");
        return 1;
    }

    int ref[pages], frame[frames];

    printf("Enter reference string:\n");
    for (i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    // Initialize frames with -1 (indicating empty frame)
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("\n--- Simulation Step-by-Step ---\n");
    for (i = 0; i < pages; i++) {
        int found = 0;

        // Check if page already exists in frames (Page Hit)
        for (j = 0; j < frames; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        // Page Fault occurs
        if (!found) {
            frame[index] = ref[i];
            index = (index + 1) % frames;
            faults++;
            printf("Page %2d -> [FAULT] Frames: ", ref[i]);
        } else {
            printf("Page %2d -> [ HIT ] Frames: ", ref[i]);
        }

        // Print current frame content
        for (j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults (FIFO) = %d\n", faults);
    printf("Total Page Hits   (FIFO) = %d\n", pages - faults);
    return 0;
}

