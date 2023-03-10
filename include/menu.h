#pragma once

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "colors.h"
#include "string.h"
#include "movement.h"

#include <stdarg.h>

typedef struct MenuOption {
    String title;
    String subtitle;
} MenuOption;

typedef struct Options{
    size_t size;
    MenuOption *option;   
} Options;

typedef struct Menu {
    String title;
    String subtitle;
    Options options;
    size_t selected;
} Menu;

Menu* newMenu(const char* title, const char* subtitle);
int addOption(Menu* menu, const char* title, const char* subtitle);
int removeOption(Menu* menu, size_t index);
int displayMenu(Menu* menu);
int freeMenu(Menu *menu);
