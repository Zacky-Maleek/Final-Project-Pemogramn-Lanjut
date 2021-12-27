#include <stdio.h>
#include <string.h>
#include <math.h>

struct data
{
    char nama_mobil[20];
    char merek[50];
    double harga_standar;
    double harga_komplit;
    int durasi;
};

struct data penyewaan[10] = {};

struct data swap[10] = {};

int main()
{
    int simpan[10];
    char nama[30], merek[30];
    float dat1, dat2;
    int a, i, j, pilih, durasi;
    strcpy(penyewaan[0].nama_mobil, "Avanza     ");
    strcpy(penyewaan[0].merek, "Toyota");
    penyewaan[0].harga_standar = 400000;
    penyewaan[0].harga_komplit = 500000;

    strcpy(penyewaan[1].nama_mobil, "Kijang Innova");
    strcpy(penyewaan[1].merek, "Toyota");
    penyewaan[1].harga_standar = 650000;
    penyewaan[1].harga_komplit = 750000;

    strcpy(penyewaan[2].nama_mobil, "Brio       ");
    strcpy(penyewaan[2].merek, "Honda  ");
    penyewaan[2].harga_standar = 300000;
    penyewaan[2].harga_komplit = 400000;

    strcpy(penyewaan[3].nama_mobil, "Jazz        ");
    strcpy(penyewaan[3].merek, "Honda  ");
    penyewaan[3].harga_standar = 350000;
    penyewaan[3].harga_komplit = 450000;

    strcpy(penyewaan[4].nama_mobil, "Grand livina");
    strcpy(penyewaan[4].merek, "Nissan");
    penyewaan[4].harga_standar = 500000;
    penyewaan[4].harga_komplit = 600000;

    strcpy(penyewaan[5].nama_mobil, "Xpander    ");
    strcpy(penyewaan[5].merek, "Mitsubishi");
    penyewaan[5].harga_standar = 550000;
    penyewaan[5].harga_komplit = 650000;

    strcpy(penyewaan[6].nama_mobil, "Alphard    ");
    strcpy(penyewaan[6].merek, "Toyota");
    penyewaan[6].harga_standar = 890000;
    penyewaan[6].harga_komplit = 990000;

    strcpy(penyewaan[7].nama_mobil, "Taycan     ");
    strcpy(penyewaan[7].merek, "Porsche");
    penyewaan[7].harga_standar = 4500000;
    penyewaan[7].harga_komplit = 4900000;

    strcpy(penyewaan[8].nama_mobil, "G class   ");
    strcpy(penyewaan[8].merek, "Mercedes-Benz");
    penyewaan[8].harga_standar = 7350000;
    penyewaan[8].harga_komplit = 7750000;

    strcpy(penyewaan[9].nama_mobil, "Aventador   ");
    strcpy(penyewaan[9].merek, "Lamborghini");
    penyewaan[9].harga_standar = 8900000;
    penyewaan[9].harga_komplit = 9500000;

    for (a = 0; a < 10; a++)
    {
        if ((penyewaan[a].harga_standar > (penyewaan[a].harga_komplit)))
        {
            penyewaan[a].durasi = 3;
        }
        else if ((penyewaan[a].harga_standar > (penyewaan[a].harga_komplit)))
        {
            penyewaan[a].durasi = 5;
        }
        else
        {
            penyewaan[a].durasi = 7;
        }
    }

menu:
    system("cls");
    printf("\n=============== PROGRAM PENYEWAAN MOBIL ==================\n");
    printf("============ Dijamin Nyaman, Aman, dan Menyenangkan =========\n");
    printf("\n 1. Data Mobil\n");
    printf(" 2. Urutkan Data Mobil\n");
    printf(" 3. Cari Data Mobil\n");
    printf(" 4. Sewa Mobil\n");
    printf("\n Masukkan Pilihan : ");
    scanf("%d", &pilih);

    if (pilih == 1)
    {
        system("cls");
        FILE *data;
        char atel[850];
        data = fopen("C:/Users/User/Downloads/Data Mobil.txt", "r");
        while (!feof(data))
        {
            fgets(atel, 850, data);
            printf("%s", atel);
        }
        fclose(data);
        sleep(10);
        goto menu;
    }

    else if (pilih == 2)
    {
        system("cls");
        printf("=============== Pilih Urutan Data ==========\n\n");
        printf(" 1. Harga Termurah\n");
        printf(" 2. Harga Termahal\n");
        printf("==>Masukkan Pilihan : ");
        scanf("%d", &pilih);

        if (pilih == 1)
        {
            for (i = 1; i < 10; i++)
            {
                for (j = i; j > 0 && penyewaan[j].harga_standar < penyewaan[j - 1].harga_standar; j--)
                {
                    insertion(j);
                }
            }
            hasil_sort();
            system("pause");
            goto menu;
        }

        else if (pilih == 2)
        {
            for (i = 1; i < 10; i++)
            {
                for (j = i; j > 0 && penyewaan[j].harga_standar > penyewaan[j - 1].harga_standar; j--)
                {
                    insertion(j);
                }
            }
            hasil_sort();
            system("pause");
            goto menu;
        }

        else
        {
            printf("Input Salah");
            sleep(2);
            goto menu;
        }
    }

    else if (pilih == 3)
    {
        int benar = 0;
        int k = 0;
        system("cls");
        printf("===== Pilih Pencarian Data =====\n\n");
        printf(" 1. Durasi\n");
        printf(" 2. Nama Mobil\n");
        printf(" 3. Merek\n");
        printf("==>Masukkan Pilihan : ");
        scanf("%d", &pilih);

        if (pilih == 1)
        {
            printf("Masukkan Durasi Penyewaan Mobil : ");
            scanf("%d", &durasi);

            for (i = 0; i < 10; i++)
            {
                if (penyewaan[i].durasi == durasi)
                {
                    benar = 12;
                    simpan[k] = i;
                    k++;
                }
            }
            if (benar == 1)
            {
                printf("\n\n");
                printf("Data Ditemukan !\n");
                printf("Nama Mobil \t\t Merek \t\t Durasi \t \n");
                for (i = 0; i < k; i++)
                {
                    printf("%s\t\t%s\t\t%d\n", penyewaan[simpan[i]].nama_mobil, penyewaan[simpan[i]].merek, penyewaan[simpan[i]].durasi);
                }
                sleep(5);
                goto menu;
            }
            else
            {
                printf("Data Tidak Ditemukan");
                sleep(2);
                goto menu;
            }
        }

        else if (pilih == 2)
        {
            fflush(stdin);
            printf("Nama Mobil : ");
            gets(nama);

            for (i = 0; i < 10; i++)
            {
                if (strcmp(penyewaan[i].nama_mobil, nama) == 0)
                {
                    benar = 1;
                    simpan[k] = i;
                    k++;
                }
            }
            if (benar == 1)
            {
                printf("\n\n");
                printf("Data Ditemukan !\n");
                printf("\nNama Mobil \t Merek \t\t Durasi \n");
                for (i = 0; i < k; i++)
                {
                    printf("%s \t\t %s \t\t %d \n", penyewaan[simpan[i]].nama_mobil, penyewaan[simpan[i]].merek, penyewaan[simpan[i]].durasi);
                }
                sleep(5);
                goto menu;
            }
            else
            {
                printf("Data Tidak Ditemukan");
                sleep(2);
                goto menu;
            }
        }

        else if (pilih == 3)
        {
            fflush(stdin);
            printf("Merek Mobil : ");
            gets(merek);

            for (i = 0; i < 10; i++)
            {
                if (strcmp(penyewaan[i].merek, merek) == 0)
                {
                    benar = 1;
                    simpan[k] = i;
                    k++;
                }
            }
            if (benar == 1)
            {
                printf("\n\n");
                printf("Data Ditemukan !\n");
                printf("Nama Mobil \t\t Merek \t\t Durasi \t\n");
                for (i = 0; i < k; i++)
                {
                    printf("%s \t\t %s \t %d \t \n", penyewaan[simpan[i]].nama_mobil, penyewaan[simpan[i]].merek, penyewaan[simpan[i]].durasi);
                }
                sleep(5);
                goto menu;
            }
            else
            {
                printf("Data Tidak Ditemukan");
                sleep(2);
                goto menu;
            }
        }

        else
        {
            printf("Input Salah");
            sleep(2);
            goto menu;
        }
    }

    else if (pilih == 4)
    {
        int k = 0;
        int benar = 0;
        double harga_standar;
        double harga_komplit;
        int uang = 750000;
        fflush(stdin);
        printf(" Merek Mobil : ");
        gets(merek);

        for (i = 0; i < 10; i++)
        {
            if (strcmp(penyewaan[i].merek, merek) == 0)
            {
                benar = 1;
                simpan[k] = i;
                k++;
            }
        }
        if (benar == 1)
        {
            printf("\n\n");
            printf("Data Ditemukan !\n");
            printf("Nama Mobil \t Merek \t\t Durasi \t\t Harga Standar \t\t Harga Komplit \n");
            for (i = 0; i < k; i++)
            {
                printf("%s \t %s \t\t %d \t\t %f \t\t %f \n", penyewaan[simpan[i]].nama_mobil, penyewaan[simpan[i]].merek, penyewaan[simpan[i]].durasi, penyewaan[simpan[i]].harga_standar, penyewaan[simpan[i]].harga_komplit);
            }
            sleep(3);
        }
        else
        {
            printf("Data Tidak Ditemukan");
            sleep(2);
            goto menu;
        }
        system("cls");
        if (benar == 1)
        {
            printf("======== Pilih Paket =========\n");
            printf("1. Paket Standar\n");
            printf("2. Paket Komplit\n");
            printf("==> Masukan Pilihan :");
            scanf("%d", &pilih);
        }
        if (pilih == 1)
        {
            printf(" Paket standar hanya termasuk penyewaan mobil saja\n ");
            printf(" Masukan nominal untuk biaya penyewaan sesuai harga yang anda pilih : ");
            scanf("%d", &harga_standar);
            if (uang >= harga_standar)
            {
                printf("Apakah anda ingin melanjutkan proses transaksi sewa mobil  : ");
                printf("\n1. Ya");
                printf("\n2. Tidak\n");
                printf("==> Masukan Pilihan :");
                scanf("%d", &pilih);
                if (pilih == 1)
                {
                    printf("\nTransaksi Berhasil");
                }
                sleep(3);
                goto menu;
            }
            else
            {
                printf("Transaksi Dibatalkan");
                sleep(2);
                goto menu;
            }
        }
        if (pilih == 2)
        {
            printf(" Paket komplit sudah termasuk dengan biaya supir\n ");
            printf(" Masukan nominal untuk biaya penyewaan sesuai harga yang anda pilih : ");
            scanf("%d", &harga_standar);
            if (uang >= harga_standar)
            {
                printf("Apakah anda ingin melanjutkan proses transaksi sewa mobil  : ");
                printf("\n1. Ya");
                printf("\n2. Tidak\n");
                printf("==> Masukan Pilihan :");
                scanf("%d", &pilih);
                if (pilih == 1)
                {
                    printf("\nTransaksi Berhasil");
                }
                sleep(3);
                goto menu;
            }
            else
            {
                printf("Transaksi Dibatalkan");
                sleep(2);
                goto menu;
            }
        }

        else
        {
            printf("Input Salah");
            sleep(2);
            goto menu;
        }
    }
}
void insertion(int j)
{
    // ubah harga
    float temp;
    temp = penyewaan[j - 1].harga_standar;
    penyewaan[j - 1].harga_standar = penyewaan[j].harga_standar;
    penyewaan[j].harga_standar = temp;

    temp = penyewaan[j - 1].harga_komplit;
    penyewaan[j - 1].harga_komplit = penyewaan[j].harga_komplit;
    penyewaan[j].harga_komplit = temp;

    char terx[100];

    // ubah merek
    strcpy(terx, penyewaan[j - 1].merek);
    strcpy(penyewaan[j - 1].merek, penyewaan[j].merek);
    strcpy(penyewaan[j].merek, terx);

    // ubah nama mobil
    strcpy(terx, penyewaan[j - 1].nama_mobil);
    strcpy(penyewaan[j - 1].nama_mobil, penyewaan[j].nama_mobil);
    strcpy(penyewaan[j].nama_mobil, terx);

    // ubah durasi
    int tepp = penyewaan[j - 1].durasi;
    penyewaan[j - 1].durasi = penyewaan[j].durasi;
    penyewaan[j].durasi = tepp;
}

void hasil_sort()
{
    printf("Mobil \t\t|\t   Merk   \t  |   \t  Harga standar  \t|\t Harga komplit\n");
    for (int a = 0; a < 10; a++)
    {
        printf("%s \t\t %s \t\t  %.f \t\t \t %.f \t\n", penyewaan[a].nama_mobil, penyewaan[a].merek, penyewaan[a].harga_standar, penyewaan[a].harga_komplit);
    }
    printf("\n\nSorting berhasil\n");
}
