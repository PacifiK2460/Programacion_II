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
    va_list onFocusArguments;
    va_list onSelectArguments;
    int (*onFocus)(struct MenuOption* self, va_list args);
    int (*onSelect)(struct MenuOption* self, va_list args);
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
int addOption(Menu* menu, const wchar_t* title, const wchar_t* subtitle,size_t onFocusArgumentsSize ,int (*onFocus)(MenuOption* self, va_list args), size_t onSelectArgumentsSize, int (*onSelect)(MenuOption* self, va_list args),size_t total_args, ...);
int removeOption(Menu* menu, size_t index);
int displayMenu(Menu* menu);
int freeMenu(Menu *menu);
