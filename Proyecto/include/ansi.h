#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define CURSOR_SAVE "\x1b[s"
#define CURSOR_RESTORE "\x1b[u"

#define CURSOR_HIDE "\x1b[?25l"
#define CURSOR_SHOW "\x1b[?25h"

#define CLEAR_SCREEN "\x1b[2J"
#define CLEAR_LINE "\x1b[2K"

#define RESET "\x1b[0m"

#define BOLD "\x1b[1m"
#define DIM "\x1b[2m"
#define UNDERLINE "\x1b[4m"
#define BLINK "\x1b[5m"
#define REVERSE "\x1b[7m"
#define HIDDEN "\x1b[8m"
#define ITALIC "\x1b[3m"

#define BRIGHT_WHITE "\x1b[97m"
#define BRIGHT_RED "\x1b[91m"
#define BRIGHT_GREEN "\x1b[92m"
#define BRIGHT_YELLOW "\x1b[93m"
#define BRIGHT_BLUE "\x1b[94m"
#define BRIGHT_MAGENTA "\x1b[95m"
#define BRIGHT_CYAN "\x1b[96m"

void CURSOR_GOTO(int x, int y);

void BG_RGB(int R, int G, int B);
void FG_RGB(int R, int G, int B);
void CURSOR_UP(int N);
void CURSOR_DOWN(int N);
void CURSOR_FORWARD(int N);
void CURSOR_BACKWARD(int N);
void CURSOR_NEXT_LINE(int N);
void CURSOR_PREVIOUS_LINE(int N);

void print_in_the_middle(char *text, int y);