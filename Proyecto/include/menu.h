#pragma once

#include <stdarg.h>
#include <string.h>

#include "list.h"

#define BUFFER_SIZE 1024

typedef struct MenuOption{
    char title[BUFFER_SIZE];
    void (*Action)(void* args);
    void* args;
} MenuOption, *PMenuOption;

typedef struct Menu{
    char title[BUFFER_SIZE];
    char description[BUFFER_SIZE];
    List options;
} Menu, *PMenu;

PMenu createMenu(char* title, char* description, int optionsCount, ...);