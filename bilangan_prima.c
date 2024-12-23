#include <stdio.h>

int prima(int a) {
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

void Faktor(int a) {
    printf("Faktor dari %d adalah: ", a);
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int a;
    int ulang;
    int batas;

    printf("Masukkan jumlah perulangan: ");
    scanf("%d", &batas);

    for (ulang = 0; ulang < batas; ulang++) {
        printf("Masukkan bilangan: ");
        scanf("%d", &a);

        if (prima(a)) {
            printf("%d adalah bilangan prima.\n", a);
        } else {
            printf("%d bukan bilangan prima.\n", a);
            Faktor(a);
        }
    }
    return 0;
}
