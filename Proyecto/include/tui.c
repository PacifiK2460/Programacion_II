#include "tui.h"

char *Color2String(Color color)
{
    char buffer[50] = {0};

    switch (color.type)
    {
    case FG:
        sprintf(buffer, "\x1b[38;2;%d;%d;%dm\0", color.r, color.g, color.b);
        break;
    case BG:
        sprintf(buffer, "\x1b[48;2;%d;%d;%dm\0", color.r, color.g, color.b);
        break;
    default:
        break;
    }

    int len = strlen(buffer);
    char *str = calloc(len + 10, sizeof(char));
    if (str == NULL)
        return NULL;

    strcpy(str, buffer);
    return str;
}

void printStatusBar(User user)
{
    ColorType type = BG;
    Color start = {255, 55, 95, type};
    Color end = {255, 55, 95, type};
    // Color end = {255, 55, 95, BG};

    // Get console size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int r = start.r;
    int g = start.g;
    int b = start.b;

    int dr = (end.r - start.r) / width;
    int dg = (end.g - start.g) / width;
    int db = (end.b - start.b) / width;

    CURSOR_GOTO(0, height);

    for (int i = 0; i < width; i++)
    {
        switch (type)
        {
        case FG:
            FG_RGB(r, g, b);
            break;
        case BG:
            BG_RGB(r, g, b);
            break;
        default:
            break;
        }
        printf(" ");

        r += dr;
        g += dg;
        b += db;
    }
}