#ifndef MENU_SELECTION_H
#include <stdio.h>
#define MENU_SELECTION_H

int MenuSelection(int selectedMenu, char menus[][100], int totalMenu)
{
    int isDone = 0;
    printf("Pilih Menu 1 - %i :\n", totalMenu);
    for (int i = 1; i <= totalMenu; i++)
    {
        printf("%i.%s \n", i, menus[i - 1]);
    }
    scanf("%i", &selectedMenu);
    printf("%s \n", menus[selectedMenu - 1]);
    printf("Apakah anda ingin mengedit lagi? | 0/1");
    scanf("%i", &isDone);
    return isDone;
}

#endif