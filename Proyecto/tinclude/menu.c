#include "menu.h"

void showMenu(PMenu menu)
{
    return NULL;
}

int addMenuOption(PMenu menu, char *title, char *description, void (*callback)())
{
    PMenuOption option = (PMenuOption)calloc(1, sizeof(MenuOption));
    StringCchCopyA(option->title, BUF_SIZE, title);
    StringCchCopyA(option->description, BUF_SIZE, description);
    option->callback = callback;

    return addNode(&menu->options, option);
}