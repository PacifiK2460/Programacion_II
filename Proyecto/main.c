#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include "include/menu.h"

int main()
{
    // App Initialization
    { // Input / Output
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);

        HANDLE hStdout;

        // Make sure there is a console to receive input.
        hStdout = GetStdHandle(STD_INPUT_HANDLE);
        if (hStdout == INVALID_HANDLE_VALUE)
            return 1;

        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hStdout == INVALID_HANDLE_VALUE)
            return 1;

        return 0;
    }

    { // Menu
        PMenu menu = createMenu("Menu", "Menu de opciones", 3,
            "Opcion 1", NULL, NULL,
            "Opcion 2", NULL, NULL,
            "Opcion 3", NULL, NULL
        );
    }


}