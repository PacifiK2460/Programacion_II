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
} Menu;

extern Menu* newMenu(const wchar_t* title, const wchar_t* subtitle);
extern int addOption(Menu* menu, const wchar_t* title, const wchar_t* subtitle, int (*onFocus)(MenuOption* self, ...), int (*onSelect)(MenuOption* self, ...));
extern int removeOption(Menu* menu, size_t index);
extern int drawMenu(Menu* menu);

extern int freeMenu(Menu *menu);
