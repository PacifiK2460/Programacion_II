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