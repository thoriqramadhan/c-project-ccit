#ifndef DAILY_MENU_H
#define DAILY_MENU_H
#include <stdio.h>
#include <string.h>
#include "../data/data.h"
// get func
void getDailyMenuList(int showHeader)
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
    strcpy(arr[indexToDelete].nama, ""); // kosongkan nama
    arr[indexToDelete].qty = 0;
    arr[indexToDelete].price = 0;
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
    updateMenuData();
}
// add func
int getNextEmptyIndex()
{
    for (int i = 0; i < menuCapacity; i++)
    {
        if (menuData[i].nama[0] == '\0')
        {
            return i;
        }
    }
    // kalau semua terisi, return -1
    return -1;
}
void addDailyMenuList()
{
    char lanjut[10];
    int banyak;
    char namaBaru[50];
    int qtyBaru, priceBaru;

    getMenuHeader("Tambah Menu");
    int sisa = 0;

lagi:
    // cek apakah masih ada slot kosong
    for (int i = 0; i < menuCapacity; i++)
        if (menuData[i].nama[0] == '\0')
            sisa++;

    if (sisa == 0)
    {
        printf("\n\t==!Maaf, menu sudah penuh (maksimal %d item)!==\n", menuCapacity);
        return;
    }

    printf("\n(masukkan 0 untuk kembali ke menu)\nBerapa menu yang ingin di tambah : ");
    if (scanf("%d", &banyak) != 1)
    {
        while (getchar() != '\n')
            ; // bersihkan stdin jika input invalid
        printf("Input tidak valid\n");
        return;
    }

    if (banyak == 0)
        return;

    if (banyak > sisa)
    {
        printf("\n\t==!Maaf, hanya tersisa %d slot lagi!==\n", sisa);
        goto lagi;
    }

    for (int i = 0; i < banyak; i++)
    {
        int idxToAdd = getNextEmptyIndex();
        if (idxToAdd == -1)
        {
            printf("\n\t==!Slot menu penuh unexpectedly!==\n");
            break;
        }

        printf("Masukkan nama menu %d : ", i + 1);
        scanf(" %[^\n]", namaBaru);

        printf("Jumlah (qty) : ");
        while (scanf("%d", &qtyBaru) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Input tidak valid! Masukkan angka untuk qty: ");
        }

        printf("Harga : ");
        while (scanf("%d", &priceBaru) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Input tidak valid! Masukkan angka untuk harga: ");
        }

        // assign
        strncpy(menuData[idxToAdd].nama, namaBaru, sizeof(menuData[idxToAdd].nama) - 1);
        menuData[idxToAdd].nama[sizeof(menuData[idxToAdd].nama) - 1] = '\0';
        menuData[idxToAdd].qty = qtyBaru;
        menuData[idxToAdd].price = priceBaru;

        // update menuDataLength jika perlu
        if (idxToAdd + 1 > menuDataLength)
        {
            menuDataLength = idxToAdd + 1;
        }

        updateMenuData();

        printf("\n\t==!Menu berhasil ditambahkan!==\n\n");
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
        // tampilkan hanya hingga menuDataLength
        for (int i = 0; i < menuDataLength; i++)
        {
            if (menuData[i].nama[0] == '\0')
                continue;
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
        printf("(Pilih angka 0 untuk keluar) \n");
        scanf("%i", &selectedMenu);
        if (selectedMenu == 0)
        {
            break;
        }
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
            switch (selectedMenuSelection)
            {
            case 1:
                printf("Masukan nama menu baru untuk menu : %s \n", menuData[selectedMenu - 1].nama);
                scanf("%s", menuData[selectedMenu - 1].nama);
                updateMenuData();
                break;
            case 2:
                printf("Masukan kuantitas baru untuk menu : %s \n", menuData[selectedMenu - 1].nama);
                while (1)
                {
                    if (scanf("%i", &menuData[selectedMenu - 1].qty) == 1)
                    {
                        while (getchar() != '\n')
                            ; // bersihkan newline
                        updateMenuData();
                        break; // input valid, keluar dari loop
                    }
                    else
                    {
                        printf("Input tidak valid! Masukkan angka.\n");
                        while (getchar() != '\n')
                            ; // hapus input buffer
                        updateMenuData();
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
                            ; // bersihkan newline
                        updateMenuData();
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