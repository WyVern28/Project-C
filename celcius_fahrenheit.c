#include <stdio.h>

void celciuskefarenheit() {
    float celcius, farenheit;
    printf("Masukkan celcius yang ingin Anda ubah: ");
    scanf("%f", &celcius);

    farenheit = (celcius * 9.0/5.0) + 32;

    printf("Hasil konversi %.2f celcius ke farenheit adalah: %.2f\n", celcius, farenheit);
}

void farenhitekecelcius() {
    float farenheit, celcius;
    printf("Masukkan farenheit yang ingin Anda ubah: ");
    scanf("%f", &farenheit);

    celcius = (farenheit - 32) * 5.0/9.0;

    printf("Hasil konversi %.2f farenheit ke celcius adalah: %.2f\n", farenheit, celcius);
}

int main() {
    int menu;

    do {
        printf("\n========== Menu ==========\n");
        printf("1. Celcius ke Farenheit\n");
        printf("2. Farenheit ke Celcius\n");
        printf("Menu pilihan Anda: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                celciuskefarenheit();
                break;
            case 2:
                farenhitekecelcius();
                break;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    } while (menu != 2);

    return 0;
}
