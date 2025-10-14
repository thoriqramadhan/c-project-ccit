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

void getDailyMenuList()
{
    int menuDataLength = sizeof(menuData) / sizeof(menuData[0]);
    printf("%i \n", menuDataLength);
    for (int i = 1; i <= menuDataLength; i++)
    {
        printf("%s \n", menuData[i - 1]);
    }
}

#endif