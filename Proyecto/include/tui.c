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

void printStatusBar()
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

char* input(char* message, int maxLength){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    CURSOR_GOTO(2, (height/2)-1);
    printf(RESET BOLD "%s\n" RESET, message);

    BG_RGB(142,161,159);
    printf(UNDERLINE);
    FG_RGB(12,12,12);
    CURSOR_GOTO(2, (height/2));
    for(int i = 0; i < maxLength; i++){
        printf(" ");
    }

    CURSOR_GOTO(2, (height/2));
    
    char* input = calloc(maxLength, sizeof(char));
    if(input == NULL)
        return NULL;

    fgets(input, maxLength, stdin);
    input[strlen(input)-1] = '\0';

    printf(RESET);
    return input;
}

void holdScreen(){
    while(!_kbhit());
}