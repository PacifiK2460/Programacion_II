#include "logic.h"

void splashScreen()
{
    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
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

    getc(stdin);
    printf(CURSOR_SHOW);
    printf(CLEAR_SCREEN);
}

PUser loginScreen(){
    while(1){
        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);

        // Print bottom and top bars
        {
            // Get console size
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

            CURSOR_GOTO(0, 0);
            for(int i = 0; i < width; i++){
                BG_RGB(240,190,1);
                printf(" ");
            }

            CURSOR_GOTO(0, height);
            for(int i = 0; i < width; i++){
                BG_RGB(240,190,1);
                printf(" ");
            }
        }

        system("pause");
    }
}