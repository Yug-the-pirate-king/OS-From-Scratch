// ==============================================================================
// Experiment 05: LRU (Least Recently Used) Page Replacement Algorithm
// ==============================================================================

#include <stdio.h>

int main() {
    int frames, pages, i, j, pos, faults = 0;

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

    int ref[pages], frame[frames], time[frames];

    printf("Enter reference string:\n");
    for (i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    // Initialize frames and usage timestamps
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    int counter = 0;
    printf("\n--- Simulation Step-by-Step ---\n");
    for (i = 0; i < pages; i++) {
        int found = 0;

        // Check if page already exists in one of the frames (Page Hit)
        for (j = 0; j < frames; j++) {
            if (frame[j] == ref[i]) {
                counter++;
                time[j] = counter; // Update recency timestamp
                found = 1;
                break;
            }
        }

        // Page Fault occurs
        if (!found) {
            // Find an empty frame if one exists
            int empty_slot = -1;
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    empty_slot = j;
                    break;
                }
            }

            if (empty_slot != -1) {
                pos = empty_slot;
            } else {
                // Find the least recently used frame (smallest timestamp)
                pos = 0;
                for (j = 1; j < frames; j++) {
                    if (time[j] < time[pos]) {
                        pos = j;
                    }
                }
            }

            frame[pos] = ref[i];
            counter++;
            time[pos] = counter;
            faults++;
            printf("Page %2d -> [FAULT] Frames: ", ref[i]);
        } else {
            printf("Page %2d -> [ HIT ] Frames: ", ref[i]);
        }

        // Display current frames
        for (j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults (LRU) = %d\n", faults);
    printf("Total Page Hits   (LRU) = %d\n", pages - faults);
    return 0;
}

