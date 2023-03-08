#include "menu.h"

int freeMenu(Menu *menu)
{
    if (menu == NULL)
        return -1;

    freeString(&menu->title);
    freeString(&menu->subtitle);

    int i;
    for (i = 0; i < menu->options.size; i++)
    {
        freeString(&menu->options.option[i].title);
        freeString(&menu->options.option[i].subtitle);
    }

    free(menu);
    return 0;
}

Menu *newMenu(const wchar_t *title, const wchar_t *subtitle)
{
    Menu *menu = calloc(1, sizeof(Menu));
    if (menu == NULL)
        return NULL;

    menu->title = *newString(title);
    if (menu->title.str == NULL)
    {
        free(menu);
        return NULL;
    }

    menu->subtitle = *newString(subtitle);
    if (menu->subtitle.str == NULL)
    {
        freeString(&menu->title);
        free(menu);
        return NULL;
    }

    menu->options.size = 0;
    menu->options.option = NULL;
    return menu;
}

int addOption(Menu *menu, const wchar_t *title, const wchar_t *subtitle, int (*onFocus)(MenuOption *self, ...), int (*onSelect)(MenuOption *self, ...))
{
    if (menu == NULL)
        return -1;

    menu->options.option = realloc(menu->options.option, (menu->options.size + 1) * sizeof(MenuOption));
    if (menu->options.option == NULL)
        return -1;

    menu->options.option[menu->options.size].title = *newString(title);
    if (menu->options.option[menu->options.size].title.str == NULL)
        return -1;

    menu->options.option[menu->options.size].subtitle = *newString(subtitle);
    if (menu->options.option[menu->options.size].subtitle.str == NULL)
    {
        freeString(&menu->options.option[menu->options.size].title);
        return -1;
    }

    menu->options.option[menu->options.size].onFocus = onFocus;
    menu->options.option[menu->options.size].onSelect = onSelect;
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
    wprintf(BOLD L"%ls" DIM ITALIC L" %ls\n" RESET, menu->title.str, menu->subtitle.str);
    // Print help
    wprintf(L" Usa " BOLD L"<w>" RESET L" y " BOLD L"<s>" RESET L" para navegar, " BOLD L"<enter>" RESET L" para seleccionar una opción, " BOLD L"<esc>" RESET L" para salir.\n");

    int i;
    for (i = 0; i < menu->options.size; i++)
    {
        if (i == menu->selected)
            wprintf(BOLD L"> %ls - " RESET ITALIC "%ls\n" RESET, menu->options.option[i].title.str, menu->options.option[i].subtitle.str);
        else
            wprintf(BOLD L"  %ls - " RESET ITALIC "%ls\n" RESET, menu->options.option[i].title.str, menu->options.option[i].subtitle.str);
    }
    return 0;
}

int displayMenu(Menu *menu)
{
    if (menu == NULL)
        return -1;

    wprintf(HIDE_CURSOR);

    if(drawMenu(menu) == -1){
        return -1;
        wprintf(SHOW_CURSOR);
    }


    // Read input and handle it in wchar
    wchar_t input;
    while (1)
    {
        input = _getwch();
        if (input == L'w' || input == L'W')
        {
            if (menu->selected > 0)
                menu->selected--;
            else
                menu->selected = menu->options.size - 1;
        }
        else if (input == L's' || input == L'S')
        {
            if (menu->selected < menu->options.size - 1)
                menu->selected++;
            else
                menu->selected = 0;
        }
        else if(input == L'\r')
        {
            if (menu->options.option[menu->selected].onSelect != NULL)
                menu->options.option[menu->selected].onSelect(&menu->options.option[menu->selected]);

            break;
        }
        else if (input == L'\x1B')
        {
            wprintf(SHOW_CURSOR);
            return -2;
        } else {
            continue;
        }

        if (menu->options.option[menu->selected].onFocus != NULL)
            menu->options.option[menu->selected].onFocus(&menu->options.option[menu->selected]);

        // Clear the only the lines printed
        int i;
        for (i = 0; i < menu->options.size + 2; i++)
        {
            wprintf(L"\033[A\033[2K");
        }

        drawMenu(menu);
    }
    wprintf(SHOW_CURSOR);

    return 0;
}