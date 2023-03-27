#include "ansi.h"

void CURSOR_GOTO(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

void BG_RGB(int R, int G, int B)
{
    printf("\033[48;2;%d;%d;%dm", R, G, B);
}

void FG_RGB(int R, int G, int B)
{
    printf("\033[38;2;%d;%d;%dm", R, G, B);
}

void CURSOR_UP(int N)
{
    printf("\033[%dA", N);
}

void CURSOR_DOWN(int N)
{
    printf("\033[%dB", N);
}

void CURSOR_FORWARD(int N)
{
    printf("\033[%dC", N);
}

void CURSOR_BACKWARD(int N)
{
    printf("\033[%dD", N);
}

void CURSOR_NEXT_LINE(int N)
{
    printf("\033[%dE", N);
}

void CURSOR_PREVIOUS_LINE(int N)
{
    printf("\033[%dF", N);
}

void print_in_the_middle(char *text, int y)
{
    // Get console size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int len = strlen(text);
    int pos = (width - len) / 2;

    CURSOR_GOTO(pos, y);
    printf("%s", text);
}