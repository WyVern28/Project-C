#include <stdio.h>

int main() {
    int ganjil = 1;

    do {
        if (ganjil % 2 != 0) {
            printf("%d\n", ganjil);
        }
        ganjil++;
    } while (ganjil <= 50);

    printf("\n");
    return 0;
}