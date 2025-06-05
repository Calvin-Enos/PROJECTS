#include "progressbar.h" // Include the header for our progressbar function
#include <stdio.h>      // For printf in main (specifically for the final newline)
#include <unistd.h>     // For usleep

// The progressbar function implementation is now in lib_progressbar.c

int main() {
    int total = 100;
    int size = 40; // Desired width of the progress bar

    // Example usage of the progress bar
    for (int i = 0; i <= total; i++) {
        progressbar(i, total, "Computing: ", size);
        usleep(100000); // Simulate work with a 100ms delay
    }
    printf("\n"); // Ensure the prompt moves to a new line after completion
    printf("Task Complete!\n"); // Notify user of completion

    // Test case: total = 0
    printf("Testing with total = 0:\n");
    progressbar(0, 0, "Test (0/0): ", size);
    printf("\nDone.\n");

    // Test case: current > total (should be capped at total for display)
    printf("Testing with current > total:\n");
    progressbar(120, 100, "Test (120/100): ", size);
    printf("\nDone.\n");

    // Test case: current = 0, total > 0
    printf("Testing with current = 0, total = 50:\n");
    progressbar(0, 50, "Test (0/50): ", size);
    printf("\nDone.\n");

    return 0;
}
