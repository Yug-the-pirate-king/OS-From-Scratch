// ==============================================================================
// Experiment 05: Optimal Page Replacement Algorithm
// ==============================================================================

#include <stdio.h>

int main() {
    int frames, pages, i, j, k, faults = 0;

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

    // Initialize all frames to -1
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("\n--- Simulation Step-by-Step ---\n");
    for (i = 0; i < pages; i++) {
        int found = 0;

        // Check if page is already present (Hit)
        for (j = 0; j < frames; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        // Page Fault occurs
        if (!found) {
            // Check if there is an empty frame first
            int empty_slot = -1;
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    empty_slot = j;
                    break;
                }
            }

            if (empty_slot != -1) {
                frame[empty_slot] = ref[i];
            } else {
                // Find the page in frame that will not be used for longest time in future
                int farthest = -1, pos = -1;

                for (j = 0; j < frames; j++) {
                    int next_use = -1;
                    for (k = i + 1; k < pages; k++) {
                        if (frame[j] == ref[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    // If a page is never referenced again, replace it immediately
                    if (next_use == -1) {
                        pos = j;
                        break;
                    }

                    if (next_use > farthest) {
                        farthest = next_use;
                        pos = j;
                    }
                }
                frame[pos] = ref[i];
            }

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

    printf("\nTotal Page Faults (Optimal) = %d\n", faults);
    printf("Total Page Hits   (Optimal) = %d\n", pages - faults);
    return 0;
}

