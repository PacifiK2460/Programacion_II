#include "logic.h"

void splashScreen()
{
    printf(CLEAR_SCREEN);
    // Get console size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    print_in_the_middle("🍔", height / 2 - 2);
    
    printf(BRIGHT_WHITE);
    print_in_the_middle("Hamburguesas Don Chuy©", height / 2 - 1);
    printf(RESET);
    
    printf(DIM);
    print_in_the_middle("By: Martinez Lara & Zavala Valdez", height / 2);
    printf(RESET);

    printf(DIM ITALIC);
    print_in_the_middle("Presiona cualquier tecla para continuar...", height);
    printf(RESET);

    getchar();
    printf(CLEAR_SCREEN);
}