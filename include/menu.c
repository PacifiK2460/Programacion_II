#include "menu.h"

int freeMenu(Menu *menu){
    if(menu == NULL)
        return -1;

    freeString(&menu->title);
    freeString(&menu->subtitle);

    int i;
    for(i = 0; i < menu->options.size; i++){
        freeString(&menu->options.option[i].title);
        freeString(&menu->options.option[i].subtitle);
    }
    
    free(menu);
    return 0;
}

Menu* newMenu(const wchar_t* title, const wchar_t* subtitle){
    Menu* menu = calloc(1, sizeof(Menu));
    if(menu == NULL)
        return NULL;

    menu->title = *newString(title);
    if(menu->title.str == NULL){
        free(menu);
        return NULL;
    }

    menu->subtitle = *newString(subtitle);
    if(menu->subtitle.str == NULL){
        freeString(&menu->title);
        free(menu);
        return NULL;
    }
    
    menu->options.size = 0;
    menu->options.option = NULL;
    return menu;
}

extern int addOption(Menu* menu, const wchar_t* title)
    if(menu == NULL)
        return -1;

    menu->options.option = realloc(menu->options.option, (menu->options.size + 1) * sizeof(MenuOption));
    if(menu->options.option == NULL)
        return -1;

    menu->options.option[menu->options.size].title = *newString(title);
    if(menu->options.option[menu->options.size].title.str == NULL)
        return -1;

    menu->options.option[menu->options.size].subtitle = *newString(subtitle);
    if(menu->options.option[menu->options.size].subtitle.str == NULL){
        freeString(&menu->options.option[menu->options.size].title);
        return -1;
    }

    menu->options.size++;
    return 0;
}

int removeOption(Menu* menu, size_t index){
    if(menu == NULL)
        return -1;

    if(index >= menu->options.size)
        return -1;

    freeString(&menu->options.option[index].title);
    freeString(&menu->options.option[index].subtitle);

    int i;
    for(i = index; i < menu->options.size - 1; i++){
        menu->options.option[i] = menu->options.option[i + 1];
    }

    menu->options.option = realloc(menu->options.option, (menu->options.size - 1) * sizeof(MenuOption));
    if(menu->options.option == NULL)
        return -1;

    menu->options.size--;
    return 0;
}

int drawMenu(Menu* menu){
    if(menu == NULL)
        return -1;

    int i;
    for(i = 0; i < menu->options.size; i++){
        printf("%ls: %ls", menu->options.option[i].title.str, menu->options.option[i].subtitle.str);
    }
    return 0;
}