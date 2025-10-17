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

int getDailyMenuList()
{
    // printf("%s\n", menuData[0].nama);
    int menuDataLength = sizeof(menuData) / sizeof(menuData[0]);
    printf("Total menu : %i\n", menuDataLength);

    for (int i = 1; i <= menuDataLength; i++)
    {
        // printf("%s \n", menuData[i - 1]);
        printf("%s\n", menuData[i - 1].nama);
    }

    return menuDataLength;
}

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
    int menuDataLength = getDailyMenuList();
    
    printf("Pilih menu yang ingin dihapus 1 - %i :\n", menuDataLength);
    int selectedMenu;

    scanf("%i", &selectedMenu);
    deleteElement(menuData, &menuDataLength, selectedMenu - 1);
    printf("Menu berhasil dihapus \n");
}

void AddDailyMenuList()
{
    char lanjut[10];
    int banyak;
    int jumlah = 1;
    char namaBaru[50];
    int qtyBaru, priceBaru;

    printf("Tambah Menu\n");

lagi:
    printf("Berapa menu yang ingin di tambah : ");
    scanf("%d", &banyak);

    for (int i = 0; i < banyak; i++)
    {
        printf("Masukkan nama menu : ");
        scanf(" %[^\n]", namaBaru);

        printf("Jumlah (qty) : ");
        scanf("%d", &qtyBaru);

        printf("Harga : ");
        scanf("%d", &priceBaru);

        strcpy(menuData[jumlah].nama, namaBaru);
        menuData[jumlah].qty = qtyBaru;
        menuData[jumlah].price = priceBaru;
        jumlah++;
    }
    printf("Apakah masih ada yang ingin di tambah (ya/no) : ");
    scanf("%s", lanjut);
    if (strcmp(lanjut, "ya") == 0)
    {
        goto lagi;
    }

    for (int i = 0; i < jumlah; i++)
    {
        printf("%d. %s (Qty: %d, Harga: %d)\n", i + 1, menuData[i].nama, menuData[i].qty, menuData[i].price);
    }
}
#endif