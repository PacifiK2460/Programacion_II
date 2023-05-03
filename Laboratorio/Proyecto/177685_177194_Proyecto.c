#include <conio.h>
#include <stdio.h>
#include <windows.h>

#include "include/menu.h"
#include "include/objects.h"
#include "include/tui.h"

void holdScreen()
{
    printf(RESET BOLD "Presiona cualquier tecla para continuar..." RESET);
    getch();
}

int main(void)
{
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);

        if (!loadDatabase())
        {
            alertScreen("Error al cargar la base de datos", ERR);
            return 1;
        }
    }

    Menu menuPrincipal = {
        .title = "Menu Principal",
        .description = "Seleccione una opcion",
        .selectedOption = 0};

    {
        if (addMenuOption(&menuPrincipal, "🔐 Iniciar Sesión") == 0)
        {
            printf("Error al agregar opcion 1\n");
            return 1;
        }

        if (addMenuOption(&menuPrincipal, "📝 Registrarse") == 0)
        {
            printf("Error al agregar opcion 2\n");
            return 1;
        }

        if (addMenuOption(&menuPrincipal, "📖 Mostrar Puntajes") == 0)
        {
            printf("Error al agregar opcion 3\n");
            return 1;
        }

        if (addMenuOption(&menuPrincipal, "🚪 Salir") == 0)
        {
            printf("Error al agregar opcion 4\n");
            return 1;
        }
    }

    do
    {
        showMenu(&menuPrincipal);

        switch (menuPrincipal.selectedOption)
        {
        case 0:
            if (!loginScreen())
            {
                alertScreen("Error al iniciar sesion", ERR);
                return 1;
            }
            break;
        case 1:
            if (!registerScreen())
            {
                alertScreen("Error al registrarse", ERR);
                return 1;
            }
            break;
        case 2:
            if (!showScoresScreen())
            {
                alertScreen("Error al mostrar puntajes", ERR);
                return 1;
            }
            break;
        case 3:
            return 0;
        default:
            continue;
        }
    } while (1);
}