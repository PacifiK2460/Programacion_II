#include "menu.h"

PMenu createMenu(char* title, char* description, int optionsCount, ...){
    PMenu menu = (PMenu)calloc(1, sizeof(Menu));
    if(menu == NULL)
        return NULL;

    strcpy(menu->title, title);
    strcpy(menu->description, description);

    va_list args;
    va_start(args, optionsCount);

    for(int i = 0; i < optionsCount; i++){
        PMenuOption option = (PMenuOption)calloc(1, sizeof(MenuOption));
        if(option == NULL)
            return NULL;

        strcpy(option->title, va_arg(args, char*));
        option->Action = va_arg(args, void*);
        option->args = va_arg(args, void*);

        if(addNode(&menu->options, option))
            return NULL;
    }

    va_end(args);

    return menu;
}

void showMenu(PMenu menu){
    // Save cursor position
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int y = csbi.dwCursorPosition.Y;
    int x = csbi.dwCursorPosition.X;

    printf(CURSOR_HIDE);
    CURSOR_GOTO(0, 0);

    // Print title
    printf( BRIGHT_WHITE "%s\n" RESET DIM "%s\n\n" RESET, menu->title, menu->description);

    // Print options
    int numero_de_opciones = menu->options.size;
    for(int opcion = 0; opcion < numero_de_opciones; opcion++){
        PMenuOption option = (PMenuOption)getNode(&menu->options, opcion);
        if(option == NULL)
            continue;

        if(opcion == menu->selectedOption)
            printf(BLINK "› " RESET);
        else
            printf(BOLD "  " RESET);
        printf(RESET "%s\n" RESET, option->title);
    }

    // Go to the bottom of the screen and print the menu help
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    CURSOR_GOTO(0, height);
    printf(RESET "🆘" ITALIC " Use las flechas para moverse y enter para seleccionar" RESET);

    getchar();
    printf(CURSOR_SHOW);
}