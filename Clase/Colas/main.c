#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node
{
    void *dato;
    struct Node *prev;
} Node, *PNode;

typedef struct Cola
{
    PNode last;
    int size;
} Cola, *PCola;

PCola _Cola;

void insertar()
{
    int *dato = 0;
    dato = (int *)malloc(sizeof(int));
    printf("Dato: ");
    scanf(" %d", &dato);

    PNode node = (PNode)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("No se pudo crear el nodo");
        return;
    }
    node->dato = (void *)dato;
    node->prev = NULL;

    if (_Cola->last == NULL)
    {
        _Cola->last = node;
        node->prev = NULL;
    }
    else
    {
        node->prev = _Cola->last;
        _Cola->last = node;
    }

    _Cola->size++;
}

void eliminar()
{
    if (_Cola->size > 0)
    {
        PNode node = _Cola->last;
        _Cola->last = node->prev;
        _Cola->size--;
        free(node);
    } else {
        printf("La cola esta vacia");
    }
}

void buscar()
{
    if (_Cola->size == 0)
    {
        printf("La cola esta vacia");
        return;
    }

    int dato = 0;
    printf("Dato: ");
    scanf(" %d", &dato);

    PNode node = _Cola->last;
    while (node != NULL)
    {
        if (*(int *)node->dato == dato)
        {
            printf("El dato %d se encuentra en la cola", dato);
            return;
        }
        node = node->prev;
    }
    printf("El dato %d no se encuentra en la cola", dato);
}

void mostrar()
{
    if (_Cola->size == 0)
    {
        printf("La cola esta vacia");
        return;
    }

    printf("[ ");
    PNode node = _Cola->last;
    while (node != NULL)
    {
        int dat = *(int *)node->dato;
        printf("%d ", dat);
        node = node->prev;
    }
    printf("]");
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    _Cola = (PCola)calloc(1, sizeof(Cola));
    if (_Cola == NULL)
    {
        printf("No se pudo crear la pila");
        return 1;
    }

    int opcion = 0;
    do
    {
        // clear screen and go to the top left corner
        // printf("\033[2J\033[1;1H");

        printf(
            "1. Insertar\n"
            "2. Eliminar\n"
            "3. Buscar\n"
            "4. Mostrar\n"
            "0. Salir\n"
            "\\> ");

        scanf(" %d", &opcion);
        switch (opcion)
        {
        case 1:
            insertar();
            break;
        case 2:
            eliminar();
            break;
        case 3:
            buscar();
            break;
        case 4:
            mostrar();
            break;
        case 0:
            break;
        default:
            break;
        }
        system("pause");
    } while (opcion != 0);
}