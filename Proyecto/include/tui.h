#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "ansi.h"
#include "users.h"
#include "windows.h"


typedef enum ColorType {
    FG,
    BG
} ColorType;

typedef struct Color {
    int r;
    int g;
    int b;
    ColorType type;
} Color;

char* monogradient(Color start, Color end, int steps);
void printStatusBar(User user);