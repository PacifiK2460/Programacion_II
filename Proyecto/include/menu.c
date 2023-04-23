#include "menu.h"

PMenu createMenu(char *title, char *description, int optionsCount, ...)
{
    PMenu menu = (PMenu)calloc(1, sizeof(Menu));
    if (menu == NULL)
        return NULL;

    menu->options.head = NULL;
    menu->options.tail = NULL;
    menu->options.size = 0;

    // Copy only the enough characters to fit the title and description
    strncpy(menu->title, title, BUFFER_SIZE);
    strncpy(menu->description, description, BUFFER_SIZE);

    va_list args;
    va_start(args, optionsCount);

    for (int i = 0; i < optionsCount; i++)
    {
        PMenuOption option = (PMenuOption)calloc(1, sizeof(MenuOption));
        if (option == NULL)
            return NULL;

        strncpy(option->title, va_arg(args, char *), BUFFER_SIZE);

        if (addNode(&menu->options, option))
            return NULL;
    }

    va_end(args);

    return menu;
}

void showMenu(PMenu menu)
{
    int key = 0;
    do
    {
        key = 0;
        // Save cursor position
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int y = csbi.dwCursorPosition.Y;
        int x = csbi.dwCursorPosition.X;

        printf(CURSOR_HIDE);
        CURSOR_GOTO(0, 0);

        // Print title
        printf(BRIGHT_WHITE "%s\n" RESET DIM "%s\n\n" RESET, menu->title, menu->description);

        // Print options
        int numero_de_opciones = menu->options.size;
        for (int opcion = 0; opcion < numero_de_opciones; opcion++)
        {
            PMenuOption option = (PMenuOption)getNode(&menu->options, opcion);
            if (option == NULL)
                continue;

            if (opcion == menu->selectedOption)
                printf(BLINK "› " RESET);
            else
                printf(BOLD "  " RESET);
            printf(RESET "%s\n" RESET, option->title);
        }

        // Go to the bottom of the screen and print the menu help
        int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        CURSOR_GOTO(0, height);
        printf(RESET "🆘" ITALIC " Use las flechas para moverse y enter para seleccionar" RESET);

        { // Read user input
            key = _getch();
            if (key == 224)
            {
                key = _getch();
                if (key == 72)
                {
                    menu->selectedOption--;
                    if (menu->selectedOption < 0)
                        menu->selectedOption = numero_de_opciones - 1;
                }
                else if (key == 80)
                {
                    menu->selectedOption++;
                    if (menu->selectedOption >= numero_de_opciones)
                        menu->selectedOption = 0;
                }
            }
        }
    } while (key != 13);
    printf(CURSOR_SHOW);
}

void destroyMenu(PMenu menu)
{
    if (menu == NULL)
        return;

    deleteList(&menu->options);
    free(menu);
}

int addOption(PMenu menu, char *title)
{
    if (menu == NULL)
        return 1;

    PMenuOption option = (PMenuOption)calloc(1, sizeof(MenuOption));
    if (option == NULL)
        return 1;

    strncpy(option->title, title, BUFFER_SIZE);

    if (addNode(&menu->options, option))
        return 1;

    return 0;
}

