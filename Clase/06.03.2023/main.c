#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

#ifdef _WIN32
#define clrscr() system("cls")
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#define GET_VARIABLE_NAME(Variable) (#Variable)

#include "../../include/menu.h"
#include "../../include/list.h"

void insertarInicio(List lista)
{
    int *numero = (int *)calloc(1, sizeof(int));
    printf("Ingresa el número a insertar: ");

    char buffer[1000];
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        if (1 == sscanf(buffer, "%d", numero))
        {
            listAddAt(lista, numero, LIST_FIRST);
            printf(GREEN BOLD "✅ Elemento insertado.\n" RESET);
            getchar();
        }
    }
    else
    {
        printf(RED BOLD "Error al leer el número.\n" RESET);
    }
}

void insertarFinal(List lista)
{
    int *numero = (int *)malloc(sizeof(int));
    printf("Ingresa el número a insertar: ");
    char buffer[1000];
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        if (1 == sscanf(buffer, "%d", numero))
        {
            if (listAddAt(lista, numero, LIST_LAST) < 0)
            {
                printf(RED BOLD "Error al insertar el elemento.\n" RESET);
            }
            else
            {
                printf(GREEN BOLD "✅ Elemento insertado.\n" RESET);
            }
            getchar();
        }
    }
    else
    {
        printf(RED BOLD "Error al leer el número.\n" RESET);
    }
}

void eliminarInicio(List lista)
{
    if (listRemoveAt(lista, LIST_FIRST, NULL) == -2)
    {
        printf(YELLOW BOLD "No hay elementos en la lista.\n" RESET);
    }

    printf(GREEN BOLD "✅ Elemento eliminado.\n" RESET);
    getchar();
}

void eliminarFinal(List lista)
{
    if (listRemoveAt(lista, LIST_LAST, NULL) == -2)
    {
        printf(YELLOW BOLD "No hay elementos en la lista.\n" RESET);
    }

    printf(GREEN BOLD "✅ Elemento eliminado.\n" RESET);
    getchar();
}

void insertarOrdenado(List lista)
{
    int *numero = (int *)malloc(sizeof(int));
    printf("Ingresa el número a insertar: ");
    char buffer[1000];
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        if (1 == sscanf(buffer, "%d", numero))
        {
            int *item = (int *)listGet(lista, LIST_FIRST);
            int index = 0;
            while (item != NULL)
            {
                if (*numero < *item)
                {
                    break;
                }
                item = (int *)listGet(lista, index);
                index++;
            }

            if (listAddAt(lista, numero, index) == -1)
            {
                printf(RED BOLD "Error al insertar el elemento.\n" RESET);
            }
            else
            {
                printf(GREEN BOLD "✅ Elemento insertado.\n" RESET);
            }

            getchar();
        }
    }
    else
    {
        printf(RED BOLD "Error al leer el número.\n" RESET);
    }
}

void eliminarEspecifico(List lista)
{
    int *numero = (int *)malloc(sizeof(int));
    printf("Ingresa el número a eliminar: ");
    char buffer[1000];
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        if (1 == sscanf(buffer, "%d", numero))
        {
            int *item = (int *)listGet(lista, LIST_FIRST);
            int index = 0;
            while (item != NULL)
            {
                if (*numero == *item)
                {
                    break;
                }
                item = (int *)listGet(lista, index);
                index++;
            }

            listRemoveAt(lista, index, NULL);

            printf(GREEN BOLD "✅ Elemento eliminado.\n" RESET);
        }
    }
    else
    {
        printf(RED BOLD "Error al leer el número.\n" RESET);
    }
}

void buscar(List lista)
{
    int numero;
    printf("Ingresa el número a buscar: ");
    char buffer[1000];
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        if (1 == sscanf(buffer, "%d", numero))
        {
            int *item = (int *)listGet(lista, LIST_FIRST);
            int index = 0;
            while (item != NULL)
            {
                if (numero == *item)
                {
                    break;
                }
                item = (int *)listGet(lista, index);
                index++;
            }

            if (item == NULL)
            {
                printf(YELLOW BOLD "No se encontró el elemento.\n" RESET);
            }
            else
            {
                printf(GREEN "%s[" BOLD "%d" RESET "] = %d\n" RESET, GET_VARIABLE_NAME(lista), index, *item);
            }

            getchar();
        }
    }
    else
    {
        printf(RED BOLD "Error al leer el número.\n" RESET);
    }
}

void imprimirLista(List lista)
{
    {

        printf(DIM "[ " RESET);
        // List lista = va_arg(args, List);
        int index = LIST_FIRST;
        int *item = (int *)listGet(lista, index++);
        while (item != NULL)
        {
            printf("%d ", *item);
            item = (int *)listGet(lista, index++);
        }
        printf(DIM "]\n ");
    }

    {
        printf(DIM "[ " RESET);
        // List lista = va_arg(args, List);
        int index = lista->size-1;
        int *item = (int *)listGet(lista, index--);
        while (item != NULL)
        {
            printf("%d ", *item);
            item = (int *)listGet(lista, index--);
        }
        printf(DIM "]\n ");
    }
    printf("Presione" RESET BOLD " ENTER " RESET DIM "para continuar..." RESET);
    getchar();
}

int main()
{
    // set locale to universal
    setlocale(LC_ALL, "en_US.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    List lista = newList();

    Menu *menu = newMenu("🐱‍👤 Listas", "Seleccione una opción");
    {
        if (menu == NULL)
        {
            printf(BOLD RED "Error: " RESET "No se pudo inicializar el menú");
            return -1;
        }

        if (addOption(menu, "Inserción al Inicio", "Inertar un número al inicio del arreglo") == -1)
        {
            printf("Error: Could not allocate memory for option 1");
            return -1;
        }

        if (addOption(menu, "Inserción al Final", "Inertar un número al Final del arreglo") == -1)
        {
            printf("Error: Could not allocate memory for option 2");
            return -1;
        }

        if (addOption(menu, "Eliminación al Inicio", "Elimina un número al Inicio del arreglo") == -1)
        {
            printf("Error: Could not allocate memory for option 3");
            return -1;
        }

        if (addOption(menu, "Eliminación al Fina", "Eliminina un número al Final del arreglo") == -1)
        {
            printf("Error: Could not allocate memory for option 5");
            return -1;
        }

        if (addOption(menu, "Inserción Ordenada", "Inserta un número en el index correspondiente al orden") == -1)
        {
            printf("Error: Could not allocate memory for option 6");
            return -1;
        }

        if (addOption(menu, "Eliminación Especifica", "Especifica un index a eliminar") == -1)
        {
            printf("Error: Could not allocate memory for option 7");
            return -1;
        }

        if (addOption(menu, "Busqueda", "Busca algun número en el arreglo") == -1)
        {
            printf("Error: Could not allocate memory for option 8");
            return -1;
        }

        if (addOption(menu, "Mostrar", "Muestra el arreglo") == -1)
        {
            printf("Error: Could not allocate memory for option 9");
            return -1;
        }
    }

    do
    {
        printf(CLEAR_SCREEN);
        // go to top left corner
        printf("\033[0;0H");
        displayMenu(menu);

        switch (menu->selected)
        {
        case 0:
            insertarInicio(lista);
            break;
        case 1:
            insertarFinal(lista);
            break;
        case 2:
            eliminarInicio(lista);
            break;
        case 3:
            eliminarFinal(lista);
            break;
        case 4:
            insertarOrdenado(lista);
            break;
        case 5:
            eliminarEspecifico(lista);
            break;
        case 6:
            buscar(lista);
            break;
        case 7:
            imprimirLista(lista);
            break;
        }

    } while (menu->selected != -1);

    freeMenu(menu);
}