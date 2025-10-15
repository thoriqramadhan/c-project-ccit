#include <stdio.h>
#include "./lib/menu-selection.h"
#include "./data/daily-menu.h"

int main()
{
    char menus[][100] = {"Lihat Menu", "Tambah Menu", "Edit Menu", "Hapus Menu"};

    int totalMenu = sizeof(menus) / sizeof(menus[0]);
    int selectedMenu;
    while (1)
    {
        MenuSelection(&selectedMenu, menus, totalMenu);
        printf("Pilihan selected menu %i \n", selectedMenu);
        if (selectedMenu == 1)
        {
            getDailyMenuList();
            break;
        }
    }
    return 0;
}
