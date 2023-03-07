#pragma once

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "colors.h"
#include "string.h"
#include <stdarg.h>

typedef struct MenuOption {
    String title;
    String subtitle;
    int (*onFocus)(struct MenuOption* self, ...);
    int (*onSelect)(struct MenuOption* self, ...);
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

Menu* newMenu(const wchar_t* title, const wchar_t* subtitle);
int addOption(Menu* menu, const wchar_t* title, const wchar_t* subtitle, int (*onFocus)(MenuOption* self, ...), int (*onSelect)(MenuOption* self, ...));
int removeOption(Menu* menu, size_t index);
int displayMenu(Menu* menu);
int freeMenu(Menu *menu);
