#include <stdio.h>
#include <unistd.h>

void progressbar(int current, int total, const char* prefix, int size) {
    int progress = (size * current) / total;
    printf("\r%s[", prefix);
    for (int i = 0; i < progress; i++) {
        printf("◼");
    }
    for (int i = progress; i < size; i++) {
        printf(".");
    }
    printf("] %d/%d", current, total);
    fflush(stdout);
}

int main() {
    int total = 100;
    int size = 40;

    for (int i = 0; i <= total; i++) {
        progressbar(i, total, "Computing: ", size);
        usleep(100000); // 100ms delay
    }
    printf("\n");
    return 0;
}

