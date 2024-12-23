#include <stdio.h>

int main() {
    int genap = 0;

    do {
        printf("%d\n", genap);
        genap += 2;
    } while (genap <= 50);

    printf("\n");
    return 0;
}
