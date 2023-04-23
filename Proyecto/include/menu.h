#pragma once

#include <stdarg.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "ansi.h"
#include "list.h"
#include "constants.h"

typedef struct MenuOption{
    char title[BUFFER_SIZE];
} MenuOption, *PMenuOption;

typedef struct Menu{
    char title[BUFFER_SIZE];
    char description[BUFFER_SIZE];
    List options;
    int selectedOption;
} Menu, *PMenu;

PMenu createMenu(char* title, char* description, int optionsCount, ...);
void showMenu(PMenu menu);