#include <stdio.h>
#include "./lib/menu-selection.h"
#include "./data/daily-menu.h"

int main()
{
    char menus[][100] = {"Lihat Menu", "Tambah Menu", "Edit Menu", "Hapus Menu", "Exit"};

    int totalMenu = sizeof(menus) / sizeof(menus[0]);
    int selectedMenu;
    while (1)
    {
        MenuSelection(&selectedMenu, menus, totalMenu);
        printf("Pilihan selected menu %i \n", selectedMenu);
        if (selectedMenu == 1)
        {
            getDailyMenuList(1);
            break;
        }
        else if (selectedMenu == 2)
        {
            addDailyMenuList();
        }
        else if (selectedMenu == 3)
        {
            editDailyMenu();
        }
        else if (selectedMenu == 4)
        {
            destroyMenuList();
        }
        else if (selectedMenu == 5)
        {
            exitMenu();
            break;
        }
    }
    return 0;
}
