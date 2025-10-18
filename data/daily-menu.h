#ifndef DAILY_MENU_H
#define DAILY_MENU_H
#include <stdio.h>
#include <string.h>

struct DailyMenu
{
    char nama[20];
    int qty;
    int price;
};

struct DailyMenu menuData[5] = {{"ayam", 1, 100}};
int menuDataLength = sizeof(menuData) / sizeof(menuData[0]);
// get func
int getDailyMenuList(int showHeader)
{
    if (showHeader)
    {
        getMenuHeader("Menu Lists");
    }
    printf("Total menu : %i\n", menuDataLength);

    for (int i = 1; i <= menuDataLength; i++)
    {
        printf("%d.%s|%i|%i \n", i, menuData[i - 1].nama, menuData[i - 1].qty, menuData[i - 1].price);
    }
}

// delete func
void deleteElement(struct DailyMenu arr[], int *n, int indexToDelete)
{
    for (int i = indexToDelete; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void destroyMenuList()
{
    getMenuHeader("Delete Menu");
    getDailyMenuList(0);

    printf("Pilih menu yang ingin dihapus 1 - %i :\n", menuDataLength);
    int selectedMenu;

    scanf("%i", &selectedMenu);
    deleteElement(menuData, &menuDataLength, selectedMenu - 1);
    printf("Menu berhasil dihapus \n");
}
// add func
void addDailyMenuList()
{
    char lanjut[10];
    int banyak;
    int jumlah = 1;
    char namaBaru[50];
    int qtyBaru, priceBaru;

    getMenuHeader("Tambah Menu");
lagi:
    if (jumlah >= 5)
    {
        printf("\n\t==!Maaf, menu sudah penuh (maksimal 5 item)!==\n");
        return;
    }

    printf("\n(masukkan 0 untuk kembali ke menu)\nBerapa menu yang ingin di tambah : ");
    scanf("%d", &banyak);

    if (banyak == 0)
        return;

    if (banyak < 5)
    {
        if (jumlah + banyak > 5)
        {
            printf("\n\t==!Maaf, hanya tersisa %d slot lagi!==\n", 5 - jumlah);
            goto lagi;
        }
        for (int i = 0; i < banyak; i++)
        {
            printf("Masukkan nama menu %d : ", i + 1);
            scanf(" %[^\n]", namaBaru);

            printf("Jumlah (qty) : ");
            scanf("%d", &qtyBaru);

            printf("Harga : ");
            scanf("%d", &priceBaru);

            printf("\n\t==!Menu berhasil ditambahkan!==\n\n");

            strcpy(menuData[jumlah].nama, namaBaru);
            menuData[jumlah].qty = qtyBaru;
            menuData[jumlah].price = priceBaru;
            jumlah++;
        }
    }
    else
    {
        printf("\n==!Maaf, maksimal input 1–4 menu per sesi!==\n");
        goto lagi;
    }

    printf("\nApakah masih ada yang ingin ditambah (ya/no) : ");
    scanf("%s", lanjut);
    if (strcmp(lanjut, "ya") == 0)
    {
        goto lagi;
    }
    else
    {
        printf("\n\nMenu yang telah di tambah :\n");
        for (int i = 0; i < jumlah; i++)
        {
            printf("%d. %s (Qty: %d, Harga: %d)\n", i + 1, menuData[i].nama, menuData[i].qty, menuData[i].price);
        }

        printf("\n  Klik enter untuk melanjutkan...\n");
        getchar();
        getchar();
    }
}

// edit func
void editDailyMenu()
{
    int selectedMenu;
    getMenuHeader("Edit Menu");
    while (1)
    {
        getDailyMenuList(0);
        printf("==================================\n");
        scanf("%i", &selectedMenu);
        if (selectedMenu < 1 || selectedMenu > menuDataLength || strlen(menuData[selectedMenu - 1].nama) <= 0)
        {
            printf("Menu tidak tersedia, silahkan pilih menu lagi \n");
            continue;
        }
        char editMenuSelection[][10] = {"nama", "qty", "price"};
        int editMenuSelectionLength = sizeof(editMenuSelection) / sizeof(editMenuSelection[0]);
        printf("%i \n", editMenuSelectionLength);
        int selectedMenuSelection;
        // loop setlah memlihih menu untuk di edit
        while (1)
        {
            printf("Apa yang ingin anda edit? \n");
            for (int i = 1; i <= editMenuSelectionLength; i++)
            {
                printf("%i.%s\n", i, editMenuSelection[i - 1]);
            }
            printf("Pilih menu anda : ");
            scanf("%i", &selectedMenuSelection);
            int isValid;
            switch (selectedMenuSelection)
            {
            case 1:
                printf("Masukan nama menu baru untuk menu : %s \n", menuData[selectedMenu - 1].nama);
                scanf("%s", menuData[selectedMenu - 1].nama);
                break;
            case 2:
                printf("Masukan kuantitas baru untuk menu : %s \n", menuData[selectedMenu - 1].nama);
                while (1)
                {
                    if (scanf("%i", &menuData[selectedMenu - 1].qty) == 1)
                    {
                        while (getchar() != '\n')
                            ;  // bersihkan newline
                        break; // input valid, keluar dari loop
                    }
                    else
                    {
                        printf("Input tidak valid! Masukkan angka.\n");
                        while (getchar() != '\n')
                            ; // hapus input buffer
                        printf("Masukan kuantitas baru untuk menu : %s \n", menuData[selectedMenu - 1].nama);
                    }
                }
                break;
            case 3:
                printf("Masukan harga baru untuk menu : %s \n", menuData[selectedMenu - 1].nama);
                while (1)
                {
                    if (scanf("%i", &menuData[selectedMenu - 1].price) == 1)
                    {
                        while (getchar() != '\n')
                            ;  // bersihkan newline
                        break; // input valid
                    }
                    else
                    {
                        printf("Input tidak valid! Masukkan angka.\n");
                        while (getchar() != '\n')
                            ; // hapus input buffer
                        printf("Masukan harga baru untuk menu : %s \n", menuData[selectedMenu - 1].nama);
                    }
                }
                break;

            default:
                continue;
                break;
            }
            printf("apakah anda masih ingin mengedit? 1|0 \n");
            int stopEdit;
            scanf("%i", &stopEdit);
            if (!stopEdit)
            {
                break;
            }
        }
    }
}

// misc
void exitMenu()
{
    printf("\t\n\n         --- Daily Catering Management ---\n");
    printf("\t=====================================");
    printf("\t\n         * Terima kasih telah menggunakan *\n");
    printf("\t       * Program Daily Menu *\n");
    printf("\t=====================================");
}

#endif