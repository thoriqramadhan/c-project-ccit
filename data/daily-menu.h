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
        printf("%d. %s \n", i, menuData[i - 1]);
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

void exitMenu()
{
    printf("\t\n\n         --- Daily Catering Management ---\n");
    printf("\t=====================================");
    printf("\t\n         * Terima kasih telah menggunakan *\n");
    printf("\t       * Program Daily Menu *\n");
    printf("\t=====================================");
}

void AddDailyMenuList()
{
    char lanjut[10];
    int banyak;
    int jumlah = 1;
    char namaBaru[50];
    int qtyBaru, priceBaru;

    printf("==================================\n");
    printf("\t +|Tambah Menu|+\n");
    printf("==================================\n\n");
    
lagi:
    if (jumlah >= 5) {
        printf("\n\t==!Maaf, menu sudah penuh (maksimal 5 item)!==\n");
        return; 
    }

    printf("\n(masukkan 0 untuk kembali ke menu)\nBerapa menu yang ingin di tambah : ");
    scanf("%d", &banyak);
    
    if(banyak == 0) return;

    if(banyak < 5){
        if (jumlah + banyak > 5) {
            printf("\n\t==!Maaf, hanya tersisa %d slot lagi!==\n", 5 - jumlah);
            goto lagi;
        }
        for (int i = 0; i < banyak; i++){
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
    }else{
        printf("\n==!Maaf, maksimal input 1–4 menu per sesi!==\n");
        goto lagi;
    }
    
    printf("\nApakah masih ada yang ingin ditambah (ya/no) : ");
    scanf("%s", lanjut);
    if(strcmp(lanjut, "ya") ==0){
            goto lagi;
    }else{
        printf("\n\nMenu yang telah di tambah :\n");
        for(int i = 0; i < jumlah; i++){
            printf("%d. %s (Qty: %d, Harga: %d)\n", i+1, menuData[i].nama, menuData[i].qty, menuData[i].price);
        }

        printf("\n  Klik enter untuk melanjutkan...\n");
        getchar();
        getchar();
    }
    
}

#endif