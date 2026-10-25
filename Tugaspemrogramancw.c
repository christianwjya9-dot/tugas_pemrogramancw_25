#include <stdio.h>
#include <string.h>

#define JUMLAH_RAK 5

void tambahStok(int stok[], int rak, int jumlah);
void kurangiStok(int stok[], int rak, int jumlah);
void tampilkanHistogram(char nama_barang[][30], int stok[], int jumlah_rak);

int main()
{
    char nama_barang[JUMLAH_RAK][30];
    int stok[JUMLAH_RAK] = {0};
    int pilihan, rak, jumlah;

    // Input nama barang untuk setiap rak
    printf("=== PENGATURAN AWAL GUDANG ===\n");
    for (int i = 0; i < JUMLAH_RAK; i++)
    {
        printf("Nama barang di rak %d: ", i + 1);
        fgets(nama_barang[i], sizeof(nama_barang[i]), stdin);
        nama_barang[i][strcspn(nama_barang[i], "\n")] = 0;
    }

    do
    {
        printf("\n=== MENU GUDANG ===\n");
        printf("1. Tambah stok\n");
        printf("2. Kurangi stok\n");
        printf("3. Laporan histogram\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1 || pilihan == 2)
        {
            printf("Nomor rak (1-%d): ", JUMLAH_RAK);
            scanf("%d", &rak);

            if (rak < 1 || rak > JUMLAH_RAK)
            {
                printf("Nomor rak tidak tersedia.\n");
                continue;
            }

            printf("Jumlah: ");
            scanf("%d", &jumlah);

            if (jumlah <= 0)
            {
                printf("Jumlah harus lebih dari 0.\n");
                continue;
            }

            if (pilihan == 1)
            {
                tambahStok(stok, rak - 1, jumlah);
            }
            else
            {
                kurangiStok(stok, rak - 1, jumlah);
            }
            printf("Stok %s sekarang: %d\n", nama_barang[rak - 1], stok[rak - 1]);
        }
        else if (pilihan == 3)
        {
            tampilkanHistogram(nama_barang, stok, JUMLAH_RAK);
        }
        else if (pilihan != 0)
        {
            printf("Pilihan tidak tersedia.\n");
        }
    } while (pilihan != 0);

    printf("Program selesai.\n");
    return 0;
}

void tambahStok(int stok[], int rak, int jumlah)
{
    stok[rak] = stok[rak] + jumlah;
}

void kurangiStok(int stok[], int rak, int jumlah)
{
    // Mencegah stok menjadi negatif
    if (jumlah > stok[rak])
    {
        printf("Gagal: stok tidak cukup (stok saat ini %d).\n", stok[rak]);
    }
    else
    {
        stok[rak] = stok[rak] - jumlah;
    }
}

void tampilkanHistogram(char nama_barang[][30], int stok[], int jumlah_rak)
{
    printf("\n=== LAPORAN STOK GUDANG ===\n");
    for (int i = 0; i < jumlah_rak; i++)
    {
        printf("Rak %d %-15s | ", i + 1, nama_barang[i]);
        for (int j = 0; j < stok[i]; j++)
        {
            printf("*");
        }
        printf(" (%d)\n", stok[i]);
    }
}