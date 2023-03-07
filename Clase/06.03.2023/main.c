#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#include "../../include/menu.h"

int main()
{
    // set locale to universal
    setlocale(LC_ALL, "");

    Menu *menu = newMenu(L"🗒️ Listas", L"Seleccione una opción 🤖");
    {
        if (menu == NULL)
        {
            wprintf(BOLD RED L"Error: " RESET L"No se pudo inicializar el menú");
            return -1;
        }

        if (addOption(menu, L"Inserción al Inicio", L"Inertar un número al inicio del arreglo", NULL, NULL) == -1)
        {
            printf("Error: Could not allocate memory for option 1");
            return -1;
        }

        if (addOption(menu, L"Inserción al Final", L"Inertar un número al Final del arreglo", NULL, NULL) == -1)
        {
            printf("Error: Could not allocate memory for option 2");
            return -1;
        }

        if (addOption(menu, L"Eliminación al Inicio", L"Elimina un número al Inicio del arreglo", NULL, NULL) == -1)
        {
            printf("Error: Could not allocate memory for option 3");
            return -1;
        }

        if (addOption(menu, L"Eliminación al Final", L"Eliminina un número al Final del arreglo", NULL, NULL) == -1)
        {
            printf("Error: Could not allocate memory for option 5");
            return -1;
        }

        if (addOption(menu, L"Inserción Ordenada", L"Inserta un número en el index correspondiente al orden", NULL, NULL) == -1)
        {
            printf("Error: Could not allocate memory for option 6");
            return -1;
        }

        if (addOption(menu, L"Eliminación Especifica", L"Especifica un index a eliminar", NULL, NULL) == -1)
        {
            printf("Error: Could not allocate memory for option 7");
            return -1;
        }

        if (addOption(menu, L"Busqueda", L"Busca algun número en el arreglo", NULL, NULL) == -1)
        {
            printf("Error: Could not allocate memory for option 8");
            return -1;
        }

        if (addOption(menu, L"Mostrar", L"Muestra el arreglo", NULL, NULL) == -1)
        {
            printf("Error: Could not allocate memory for option 9");
            return -1;
        }
    }

    int result = displayMenu(menu);

    if (result == -1)
    {
        wprintf(BOLD RED L"Error: " RESET L"No se pudo inicializar el menú");
        return -1;
    }
    else if (result == -2)
    {
        wprintf(BOLD YELLOW L"Warn: " RESET L"Salida temprana no manejada");
        return -1;
    }
    else if (result != 0)
    {
        wprintf(L"Codigo de salida no manejado: %d", result);
    }

    freeMenu(menu);
}