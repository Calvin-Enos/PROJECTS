#include "progressbar.h"
#include <stdio.h> // For printf, fflush

void progressbar(int current, int total, const char* prefix, int size) {
    if (total == 0) {
        // Handle division by zero or invalid total
        printf("\r%s[", prefix);
        for (int i = 0; i < size; i++) {
            printf(".");
        }
        printf("] %d/%d", current, total); // Or display something like "N/A"
        fflush(stdout);
        return;
    }

    // Ensure current does not exceed total for display purposes
    if (current > total) {
        current = total;
    }

    int progress_scaled; // Progress in terms of characters in the bar
    if (current == 0) { // Avoid division if current is 0 but total is not
        progress_scaled = 0;
    } else {
        progress_scaled = (size * current) / total;
    }

    // Ensure progress_scaled does not exceed size due to potential rounding or input issues
    if (progress_scaled > size) {
        progress_scaled = size;
    }

    printf("\r%s[", prefix);
    for (int i = 0; i < progress_scaled; i++) {
        printf("◼");
    }
    for (int i = progress_scaled; i < size; i++) {
        printf(".");
    }
    printf("] %d/%d", current, total);
    fflush(stdout);
}
