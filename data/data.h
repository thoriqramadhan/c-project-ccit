#ifndef MENU_DATA
#define MENU_DATA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct menu
struct DailyMenu
{
    char nama[20];
    int qty;
    int price;
};

// Data default (kalau file belum ada atau kosong)
struct DailyMenu menuData[5] = {
    {"ayam", 1, 10000},
    {"nasi", 1, 5000},
    {"teh", 1, 3000},
    {"kopi", 1, 4000},
    {"air", 1, 2000}};

// Variabel global
int menuDataLength = 5;
int menuCapacity = sizeof(menuData) / sizeof(menuData[0]);

char dataLocation[50] = "./data/data.txt";

void loadMenuData()
{
    FILE *file = fopen(dataLocation, "r");

    if (!file)
    {
        file = fopen(dataLocation, "w");
        if (!file)
        {
            perror("Gagal membuat file data.txt");
            exit(1);
        }

        for (int i = 0; i < menuDataLength; i++)
        {
            fprintf(file, "%s %d %d\n",
                    menuData[i].nama,
                    menuData[i].qty,
                    menuData[i].price);
        }

        fclose(file);
        return;
    }

    struct DailyMenu tempData[100];
    int count = 0;
    while (fscanf(file, "%19s %d %d",
                  tempData[count].nama,
                  &tempData[count].qty,
                  &tempData[count].price) == 3)
    {
        count++;
        if (count >= menuCapacity)
            break;
    }

    fclose(file);

    if (count > 0)
    {
        memcpy(menuData, tempData, count * sizeof(struct DailyMenu));
        menuDataLength = count;
    }
}

void updateMenuData()
{
    FILE *file = fopen(dataLocation, "w");
    if (!file)
    {
        perror("Gagal mengupdate data.txt");
        exit(1);
    }

    for (int i = 0; i < menuDataLength; i++)
    {
        if (menuData[i].nama[0] == '\0')
            continue;
        fprintf(file, "%s %d %d\n",
                menuData[i].nama,
                menuData[i].qty,
                menuData[i].price);
    }

    fclose(file);
}
#endif
