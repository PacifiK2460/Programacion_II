#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "ansi.h"
#include "windows.h"
#include <conio.h>


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

enum AlertType {
    INFO,
    WARNING,
    ERR
};

char* monogradient(Color start, Color end, int steps);
void printStatusBar();

// TUI: Terminal User Interface

char* input(char* message, int maxLength);

void holdScreen();

void alertScreen(char *message, int type);