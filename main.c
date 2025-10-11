#include <stdio.h>

int MenuSelection(int selectedMenu, char menus[][100], int totalMenu);
int main()
{
    char menus[][100] = {"Lihat Menu", "Tambah Menu", "Edit Menu", "Hapus Menu"};
    int totalMenu = sizeof(menus) / sizeof(menus[0]);
    int selectedMenu;
    while (1)
    {
        int isDone = MenuSelection(selectedMenu, menus, totalMenu);
        if (isDone)
        {
            break;
        }
    }
    return 0;
}

int MenuSelection(int selectedMenu, char menus[][100], int totalMenu)
{
    int isDone = 0;
    printf("Pilih Menu 1 - %i :\n", totalMenu);
    for (int i = 1; i <= totalMenu; i++)
    {
        printf("%i.%s \n", i, menus[i - 1]);
    }
    scanf("%i", &selectedMenu);
    printf("%i \n", selectedMenu);
    scanf("%i", &isDone);
    return 0;
}