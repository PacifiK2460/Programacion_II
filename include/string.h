#pragma once

#include<stdlib.h>
#include<string.h>

typedef struct String {
    char* str;
    size_t len;
} String;

extern int newStringFrom(const char* src, String* dest);
extern void freeString(String* str);