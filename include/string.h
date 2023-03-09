#pragma once

#include<stdlib.h>
#include<wchar.h>

typedef struct String {
    wchar_t* str;
    size_t len;
} String;

extern String* newString(const wchar_t* str);
extern void freeString(String* str);