#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include "include/menu.h"
#include "include/tui.h"
#include "include/logic.h"

int main()
{
    // App Initialization
    { // Input / Output
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        // SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);

        HANDLE hStdout;

        // Make sure there is a console to receive input.
        hStdout = GetStdHandle(STD_INPUT_HANDLE);
        if (hStdout == INVALID_HANDLE_VALUE)
            return 1;

        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hStdout == INVALID_HANDLE_VALUE)
            return 1;
    }

    loadDatabase();
    
    { // Menu


        splashScreen();
        while (1)
        {
            printf(CLEAR_SCREEN);
            printf(RESET);

            PPersonal user = loginScreen();

            if(user->tipo == ADMIN)
                adminMenu(user);
            else if(user->tipo == USER)
                userMenu(user);

        }
    }
}