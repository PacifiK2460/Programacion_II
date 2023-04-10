#include "menu.h"

int freeMenu(Menu *menu)
{
    if (menu == NULL)
        return -1;

    free(menu);
    return 0;
}

Menu *newMenu(const char *title, const char *subtitle)
{
    Menu *menu = calloc(1, sizeof(Menu));
    if (menu == NULL)
        return NULL;

    if (newStringFrom(title, &menu->title) == -1){
        free(menu);
        return NULL;
    }
    if (newStringFrom(subtitle, &menu->subtitle) == -1){
        free(menu);
        return NULL;
    }

    return menu;
}

int addOption(Menu *menu, const char *title, const char *subtitle)
{
    if (menu == NULL)
        return -1;

    MenuOption *new = realloc(menu->options.option, (menu->options.size + 1) * sizeof(MenuOption));
    if (new == NULL){
        return -1;
    }

    // Go to that new memory block and clean it up
    new[menu->options.size] = (MenuOption){0};

    menu->options.option = new;
    if( newStringFrom(title, &menu->options.option[menu->options.size].title) == -1){
        return -1;
    }

    if( newStringFrom(subtitle, &menu->options.option[menu->options.size].subtitle) == -1){
        return -1;
    }

    menu->options.size++;
    return 0;
}

int removeOption(Menu *menu, size_t index)
{
    if (menu == NULL)
        return -1;

    if (index >= menu->options.size)
        return -1;

    freeString(&menu->options.option[index].title);
    freeString(&menu->options.option[index].subtitle);

    int i;
    for (i = index; i < menu->options.size - 1; i++)
    {
        menu->options.option[i] = menu->options.option[i + 1];
    }

    menu->options.option = realloc(menu->options.option, (menu->options.size - 1) * sizeof(MenuOption));
    if (menu->options.option == NULL)
        return -1;

    menu->options.size--;
    return 0;
}

int drawMenu(Menu *menu)
{
    if (menu == NULL)
        return -1;

    // Print title and subtitle in bold and dimmed
    printf(BOLD "%s" DIM ITALIC "\n %s\n" RESET, menu->title.str, menu->subtitle.str);
    // Print help
    // printf("🆘 Usa " BOLD "w" RESET " }y " BOLD "s" RESET " para navegar, " BOLD "enter" RESET " para seleccionar una opción, " BOLD "esc" RESET " para salir.\n");

    int i;
    for (i = 0; i < menu->options.size; i++)
    {
        printf(INVERTED" %-d " RESET BOLD " %s - " RESET ITALIC "%s\n" RESET,i, menu->options.option[i].title.str, menu->options.option[i].subtitle.str);
        // if (i == menu->selected)
        //     printf(BOLD "> %s - " RESET ITALIC "%s\n" RESET, menu->options.option[i].title.str, menu->options.option[i].subtitle.str);
        // else
        //     printf(BOLD "  %s - " RESET ITALIC "%s\n" RESET, menu->options.option[i].title.str, menu->options.option[i].subtitle.str);
    }

    printf("Selecciona una opción: ");
    return 0;
}

int displayMenu(Menu *menu)
{
    if (menu == NULL)
        return -1;

    if (drawMenu(menu) == -1)
    {
        return -1;
        printf(SHOW_CURSOR);
    }

    // Read input
    int numero;
    char buffer[1000];
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        if (1 == sscanf(buffer, "%d", &numero))
        {
            menu->selected = numero;
        }
    }
    else {
        printf(RED BOLD "Error al leer el número.\n" RESET);
    }

    return 0;
}