#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#include "include/menu.h"

int main()
{
    /* We wish to use the user's current locale. */
    setlocale(LC_ALL, "en_US.UTF-8");

    Menu *menu = newMenu("Title", "Subtitle");
    if (menu == NULL)
    {
        printf("Error: Could not allocate memory for menu");
        return -1;
    }

    if (addOption(menu, "Option 1", "Subtitle 1") == -1)
    {
        printf("Error: Could not allocate memory for option 1");
        return -1;
    }

    if (addOption(menu, "Option 2", "Subtitle 2") == -1)
    {
        printf("Error: Could not allocate memory for option 2");
        return -1;
    }

    int result = displayMenu(menu);

    freeMenu(menu);
}