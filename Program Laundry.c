#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

typedef struct {
    char layanan[10][100];
    int jumlah[10];
    float hargaPerUnit[10];
    float totalHarga;
    float amountPaid;
    int totalLayanan;
    char pengguna[50];
    char metodePembayaran[10];
} LaundryStruk;

LaundryStruk struk = { .totalHarga = 0.0, .totalLayanan = 0 };
void loadingawal() {
    system("cls");
    printf("\033[0;32m");

    printf("\n\n\n\n\n");
    printf("\t\t\t\tSELAMAT DATANG DI TUGAS RANCANG ASDOS DDP B (2024) \n");
    printf("\t\t\t\t\t\t    Loading:\n\n");

    for (int i = 0; i <= 50; i++) {
        int percentage = (i * 2);
        printf("\r\t\t\t%3d%% [", percentage);
        for (int j = 0; j < i; j++) {
            printf("=");
        }
        for (int k = i; k < 50; k++) {
            printf(" ");
        }
        printf("]");
        fflush(stdout);
        usleep(100000);
    }

    printf("\n\n\t\t\t\t\t\tLoading Selesai!\n");

    printf("\033[0m");
}
void displayMainMenu() {
    system("cls");
    printf("\t\t\t============= LOGIN =============\n");
    printf("\t\t\t= 1. Login                      =\n");
    printf("\t\t\t= 2. Keluar                     =\n");
    printf("\t\t\t=================================\n");
}

void loading(int progress) {
    printf("Loading");
    for (int i = 0; i < progress; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

int loginUser() {
    char inputUsername[50], inputPassword[50];
    system("cls");
    printf("\t\t\t======== LOGIN ========\n");
    printf("\t\t\tMasukkan Username: ");
    fgets(inputUsername, sizeof(inputUsername), stdin);
    inputUsername[strcspn(inputUsername, "\n")] = 0;
    
    printf("\t\t\tMasukkan Password: ");
    fgets(inputPassword, sizeof(inputPassword), stdin);
    inputPassword[strcspn(inputPassword, "\n")] = 0;
    system("cls");
    loading(2);

    if (strcmp(inputUsername, "admin") == 0 && strcmp(inputPassword, "123") == 0) {
        printf("Login berhasil! Selamat datang, %s.\n\n", inputUsername);
        strcpy(struk.pengguna, inputUsername);
        loading(2);
        return 1;
    } else {
        printf("Login gagal! Username atau password salah.\nTekan enter untuk mengulangi login\n");
        getchar();
        loginUser();
    }
    return 1;
}

void tambahkanLayanan(const char* namaLayanan, int jumlah, float hargaPerUnit) {
    if (struk.totalLayanan < 10) {
        strcpy(struk.layanan[struk.totalLayanan], namaLayanan);
        struk.jumlah[struk.totalLayanan] = jumlah;
        struk.hargaPerUnit[struk.totalLayanan] = hargaPerUnit;
        struk.totalHarga += jumlah * hargaPerUnit;
        struk.totalLayanan++;
    } else {
        printf("Maksimum layanan telah tercapai. Tidak dapat menambah lebih banyak layanan.\n");
        loading(2);
    }
}

void tampilkanStruk() {
    int pilihan;
    char tambahLayanan;

    if (struk.totalLayanan == 0) {
        printf("Belum ada layanan yang dipilih.\n\n");
        loading(2);
        return;
    }

    loading(2);
    system("cls");
    printf("1. Tunai\n");
    printf("2. QRIS\n");
    printf("3. Kembali\n");
    printf("Pilih metode pembayaran atau batalkan pembayaran: ");
    if (scanf("%d", &pilihan) != 1) {
        while (getchar() != '\n'); 
        printf("Pilihan invalid! Pilihan harus berupa angka. Tekan Enter untuk mengulangi...");
        getchar();
        printf("\n");
        return tampilkanStruk();
    } else if (pilihan == 1) {
        strcpy(struk.metodePembayaran, "Tunai");
    } else if (pilihan == 2) {
        strcpy(struk.metodePembayaran, "QRIS");
    } else if (pilihan == 3) {
        return;
    } else {
        printf("Pilihan tidak valid. Metode pembayaran tidak diubah.\n");
        loading(2);
        return tampilkanStruk();
    }
    loading(2);
    printf("Metode pembayaran telah dipilih: %s\n", struk.metodePembayaran);
    loading(2);
    system("cls");
    printf("\n\n");
    printf("\t\t\t================================= STRUK LAUNDRY ==================================\n");
    printf("\t\t\t||Nama Pengguna     : %s\t\t\t\t\t\t\t||\n", struk.pengguna);
    printf("\t\t\t----------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < struk.totalLayanan; i++) {
        printf("\t\t\t||%d. %s - %d unit, 1 unit per harga Rp %.2f = Rp %.2f\t||\n",
               i + 1, struk.layanan[i], struk.jumlah[i],
               struk.hargaPerUnit[i], struk.jumlah[i] * struk.hargaPerUnit[i]);
    }
    
    printf("\t\t\t----------------------------------------------------------------------------------\n");
    printf("\t\t\t||Total Harga       : Rp %.2f\t\t\t\t\t\t||\n", struk.totalHarga);
    printf("\t\t\t||Metode Pembayaran : %s\t\t\t\t\t\t\t||\n", struk.metodePembayaran);
    printf("\t\t\t==================================================================================\n\n");
    do {
        printf("\t\t\tMasukkan jumlah uang yang akan dibayar: ");
        if (scanf("%f", &struk.amountPaid) != 1) {
            while (getchar() != '\n'); 
            printf("\t\t\tInput tidak valid! Silakan masukkan angka.\n");
            loading(2);
            return;
        }else if (struk.amountPaid < struk.totalHarga) {
            printf("\t\t\tJumlah yang dibayar kurang dari total harga (Rp %.2f). Silakan masukkan jumlah yang cukup.\n", struk.totalHarga);
        }
    } while (struk.amountPaid < struk.totalHarga);
    printf("\t\t\tApakah Anda ingin menambahkan layanan lagi? (y/n): ");
    scanf(" %c", &tambahLayanan);

    if (tambahLayanan == 'y' || tambahLayanan == 'Y') {
        return;
    } else {
        system("cls");
        printf("\n================================= STRUK LAUNDRY ==================================\n");
        printf("||Nama Pengguna     : %s\t\t\t\t\t\t\t||\n", struk.pengguna);
        printf("----------------------------------------------------------------------------------\n");
        
        for (int i = 0; i < struk.totalLayanan; i++) {
            printf("%d. %s - %d unit, 1 unit per harga Rp %.2f = Rp %.2f\t||\n",
                   i + 1, struk.layanan[i], struk.jumlah[i],
                   struk.hargaPerUnit[i], struk.jumlah[i] * struk.hargaPerUnit[i]);
        }
        
        printf("----------------------------------------------------------------------------------\n");
        printf("||Total Harga       : Rp %.2f\t\t\t\t\t\t||\n", struk.totalHarga);
        printf("||Metode Pembayaran : %s\t\t\t\t\t\t\t||\n", struk.metodePembayaran);
        printf("||Jumlah Dibayar    : Rp %.2f\t\t\t\t\t\t||\n", struk.amountPaid);
        printf("||Kembalian         : Rp %.2f\t\t\t\t\t\t\t||\n", struk.amountPaid - struk.totalHarga);
        printf("==================================================================================\n\n");
        printf("Terima kasih sudah menggunakan laundry kita.\n\n");
        system("pause");
        return;
    }
}

void resetStruk() {
    struk.totalHarga = 0.0;
    struk.totalLayanan = 0;
    printf("Pilihan layanan telah direset.\n\n");
    loading(3);
}

void layananKiloan() {
    float hargaPerKilo = 10000.0;
    float jumlahKilo;
    char tambahLagi;

    do {
        printf("=== LAUNDRY KILOAN ===\n");
        printf("Masukkan jumlah kilo: ");
        if (scanf("%f", &jumlahKilo) != 1) {
            getchar();
            printf("Input tidak valid. Silakan masukkan angka.\n\n");
            return;
        }else if (jumlahKilo < 0) {
            printf("Jumlah kilo tidak boleh negatif. Silakan masukkan jumlah kilo yang valid.\n\n");
            return layananKiloan();
        }
        getchar();

        loading(2);
        tambahkanLayanan("Laundry Kiloan", (int)jumlahKilo, hargaPerKilo);

        printf("Apakah Anda ingin menambahkan lagi? (y/n): ");
        scanf(" %c", &tambahLagi);
        system("cls");
    } while (tambahLagi == 'y');
}

void layananSatuan() {
    float hargaPerItem = 5000.0;
    int jumlahItem;
    char tambahLagi;

    do {
        printf("=== LAUNDRY SATUAN ===\n");
        printf("Masukkan jumlah pakaian: ");
        if (scanf("%d", &jumlahItem) != 1) {
            getchar();
            printf("Input tidak valid. Silakan masukkan angka.\n\n");
            return;
        }else if(jumlahItem < 0) {
            printf("Jumlah pakaian tidak boleh negatif. Silakan masukkan jumlah pakaian yang valid.\n\n");
            return layananSatuan();
        }
        getchar();

        loading(2);
        tambahkanLayanan("Laundry Satuan", jumlahItem, hargaPerItem);

        printf("Apakah Anda ingin menambahkan lagi? (y/n): ");
        scanf(" %c", &tambahLagi);
        system("cls");
    } while (tambahLagi == 'y');
}

void layananSetrika() {
    float hargaPerItem = 7000.0;
    int jumlahItem;
    char tambahLagi;

    do {
        printf("=== LAUNDRY SETRIKA ===\n");
        printf("Masukkan jumlah pakaian yang akan disetrika: ");
        if (scanf("%d", &jumlahItem) != 1) {
            getchar();
            printf("Input tidak valid. Silakan masukkan angka.\n\n");
            return;
        }else if (jumlahItem < 0) {
            printf("Jumlah pakaian tidak boleh negatif. Silakan masukkan jumlah pakaian yang valid.\n\n");
            return layananSetrika();
        }
        getchar();

        loading(2);
        tambahkanLayanan("Laundry Setrika", jumlahItem, hargaPerItem);

        printf("Apakah Anda ingin menambahkan lagi? (y/n): ");
        scanf(" %c", &tambahLagi);
        system("cls");
    } while (tambahLagi == 'y');
}
void author() {
    system("cls"); 
    printf("\t\t\t======== AUTHOR PROJECT LAUNDRY ==========\n");
    printf("\t\t\t||Author: \t\t\t\t||%s\n", "\n\t\t\t||WILLIAM PRASETYO UTOMO(672024125)\t||\n\t\t\t||ADELIN MAYSIA ANTARESTY(672024119)\t||\n\t\t\t||EKA YULIANA(672024120)\t\t||\n\t\t\t||GEOFALDY MORITS KOLINTAMA(672024112)\t||");
    printf("\t\t\t||Kelas: %s\t\t\t||\n", "ASDOSDDP(B)");
    printf("\t\t\t||Semester: %s\t\t\t\t||\n", "1");
    printf("\t\t\t||Tahun: %s\t\t\t\t||\n", "2024");
    printf("\t\t\t==========================================\n");
    system("pause");
}
void layanan() {
    int pilihanLayanan;

    while (1) {
        system("cls");
        printf("\t\t\t=========Selamat Datang di Laundry ========\n");
        printf("\t\t\t========== PILIH LAYANAN LAUNDRY ==========\n");
        printf("\t\t\t|| 1. Laundry Kiloan                     ||\n");
        printf("\t\t\t|| 2. Laundry Satuan                     ||\n");
        printf("\t\t\t|| 3. Laundry Setrika                    ||\n");
        printf("\t\t\t|| 4. Tampilkan Struk                    ||\n");
        printf("\t\t\t================ LAINNYA ==================\n");
        printf("\t\t\t|| 44. Author                            ||\n");
        printf("\t\t\t|| 55. Reset Pilihan                     ||\n");
        printf("\t\t\t|| 99. Kembali ke Menu Utama             ||\n");
        printf("\t\t\t===========================================\n");
        printf("\t\t\tPilih layanan atau yang lainnya: ");
        scanf("%d", &pilihanLayanan);
        getchar();

        switch (pilihanLayanan) {
            case 1:
                system("cls");
                layananKiloan();
            break;
            case 2:
                system("cls");
                layananSatuan();
            break;
            case 3:
                system("cls");
                layananSetrika();
            break;
            case 4:
                system("cls");
                tampilkanStruk();
            break;
            case 44:
                system("cls");
                author();
            break;
            case 55:
                system("cls");
                resetStruk();
            break;
            case 99:
                printf("\t\t\tKembali ke menu utama.\n\n");
                system("pause");
            return;
            default:
                printf("Pilihan tidak valid.\n");
            break;
        }
    }
}

int main() {
    int choice, masuk = 0;
    loadingawal();
    while (1) {
        system("color d");
        displayMainMenu();
        printf("\t\t\tPilih menu: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                masuk = loginUser ();
                if (masuk) {
                    layanan();
                }
                break;
            case 2:
                system("cls");
                printf("Terima kasih! Sampai Jumpa.\n");
                exit(0);
                break;
            default:
                printf("\n\t\t\tPilihan tidak valid. Silakan coba lagi.\n\n");
                break;
        }
    }
    return 0;
}
