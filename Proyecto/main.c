#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include "include/menu.h"
#include "include/tui.h"
#include "include/users.h"
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

    // Skip login for now
    // User user = {"admin", "admin", ADMIN};
    { // Menu
        // PMenu menu = createMenu("Menu Principal 🍔", "Escoge alguna opción ✅", 4,
        //                         "🪙 Cargar Precios", NULL, NULL,
        //                         "✏️ Modificar Precios", NULL, NULL,
        //                         "🪪 Agregar Personal", NULL, NULL,
        //                         "💻 Generar Reportes", NULL, NULL);

        // if (menu == NULL)
        //     return 1;

        splashScreen();
        while (1)
        {
            printf(CLEAR_SCREEN);
            printf(RESET);

            PUser user = loginScreen();

            if(user->type == ADMIN){
                adminMenu(user);
            }else{
                // userMenu(user);
            };

            // printStatusBar(user);
            // showMenu(menu);
            //santiano se la come
            getc(stdin);
        }
    }
}