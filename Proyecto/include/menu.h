#pragma once

#include <string.h>

#include "LIST.h"
#include "ansi.h"
#include "IO.h"

#define BUF_SIZE 255

typedef struct MenuOption{
    char title[BUF_SIZE];
    char description[BUF_SIZE];

    void (*callback)();
} MenuOption, *PMenuOption;

typedef struct Menu{
    char title[BUF_SIZE];
    char description[BUF_SIZE];
    POutputSubsciption output;

    List options;
} Menu, *PMenu;

void showMenu(PMenu menu);

int addMenuOption(PMenu menu, char* title, char* description, void (*callback)());