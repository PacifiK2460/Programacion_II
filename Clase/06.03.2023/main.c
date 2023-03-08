#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#include "../../include/menu.h"
#include "../../include/list.h"

void insertarInicio(List lista)
{
    int *numero = malloc(sizeof(int));
    wprintf(L"Ingresa el número a insertar: ");
    wscanf(L"%d", numero);
    listAdd(lista, numero);
}

void insertarFinal(List lista)
{
    int *numero = malloc(sizeof(int));
    wprintf(L"Ingresa el número a insertar: ");
    wscanf(L"%d", numero);
    listAdd(lista, numero);
}

void eliminarInicio(List lista)
{
    listRemoveAt(lista, LIST_FIRST, NULL);
}

void eliminarFinal(List lista)
{
    listRemoveAt(lista, LIST_LAST, NULL);
}

void insertarOrdenado(List lista)
{
    int *numero = malloc(sizeof(int));
    wprintf(L"Ingresa el número a insertar: ");
    wscanf(L"%d", numero);

    int *item = listGet(lista, LIST_FIRST);
    int index = 0;
    while (item != NULL)
    {
        if (*numero < *item)
        {
            break;
        }
        item = listGet(lista, index);
        index++;
    }

    listAddAt(lista, numero, index);
}

void eliminarEspecifico(List lista)
{
    int *numero = malloc(sizeof(int));
    wprintf(L"Ingresa el número a eliminar: ");
    wscanf(L"%d", numero);

    int *item = listGet(lista, LIST_FIRST);
    int index = 0;
    while (item != NULL)
    {
        if (*numero == *item)
        {
            break;
        }
        item = listGet(lista, index);
        index++;
    }

    listRemoveAt(lista, index, NULL);
}

void buscar(List lista)
{
    int *numero = malloc(sizeof(int));
    wprintf(L"Ingresa el número a eliminar: ");
    wscanf(L"%d", numero);

    int *item = listGet(lista, LIST_FIRST);
    int index = 0;
    while (item != NULL)
    {
        if (*numero == *item)
        {
            break;
        }
        item = listGet(lista, index);
        index++;
    }
}

void imprimirLista(List lista)
{
    wprintf(L"[ ");
    ListItem *item = listGet(lista, LIST_FIRST);
    int index = 0;
    while (item != NULL)
    {
        wprintf(L"%d ", item);
        item = listGet(lista, index);
        index++;
    }
    wprintf(L"]\n");
}

int main()
{
    // set locale to universal
    setlocale(LC_ALL, "");
    wprintf(CLEAR_SCREEN);

    List lista;
    lista = newList();

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

    int result;
    do
    {
        result = displayMenu(menu);
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
    } while (result != 0);

    freeMenu(menu);
}