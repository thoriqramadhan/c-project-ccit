#ifndef DAILY_MENU_H
#define DAILY_MENU_H
#include <stdio.h>
struct DailyMenu
{
    char nama[20];
    int qty;
    int price;
};

struct DailyMenu menuData[] = {"ayam", 1, 100};

int getDailyMenuList()
{
    int menuDataLength = sizeof(menuData) / sizeof(menuData[0]);
    printf("%i \n", menuDataLength);
    for (int i = 1; i <= menuDataLength; i++)
    {
        printf("%s \n", menuData[i - 1]);
    }
}

// Delete element by moving elements to the left and resize the array
void deleteElement(struct DailyMenu arr[], int *n, int indexToDelete)
{
    for (int i = indexToDelete; i < *n -1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    
}
// Function to delete the data by select the data than calling the deleteElement function
void destroyMenuList()
{
    int menuDataLength = sizeof(menuData) / sizeof(menuData[0]);
    printf("%i \n", menuDataLength);
    for (int i = 1; i <= menuDataLength; i++)
    {
        printf("%s \n", menuData[i - 1]);
    }

    printf("Pilih menu yang ingin dihapus 1 - %i :\n", menuDataLength);
    int selectedMenu;

    scanf("%i", &selectedMenu);
    deleteElement(menuData, &menuDataLength, selectedMenu - 1);
    printf("Menu berhasil dihapus \n");
}

#endif