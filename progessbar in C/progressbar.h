#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <stdio.h> // For fflush, printf in the implementation

// Function signature for the progress bar
void progressbar(int current, int total, const char* prefix, int size);

#endif // PROGRESSBAR_H
