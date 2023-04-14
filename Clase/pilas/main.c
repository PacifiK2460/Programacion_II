#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define COLORS 0

#if COLORS

#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#elif !COLORS

#define BOLD ""
#define RESET ""

#define RED ""
#define GREEN ""
#define YELLOW ""

#endif

typedef struct Node
{
    void *dato;
    struct Node *next;
} Node, *PNode;

typedef struct Pila
{
    PNode top;
    int size;
} Pila, *PPila;

PPila _Pila;

int Push(PPila pila, void *dato)
{
    PNode node = (PNode)malloc(sizeof(Node));
    if (node == NULL)
    {
        return 0;
    }
    node->dato = dato;
    node->next = NULL;

    if (pila->top == NULL)
    {
        pila->top = node;
    }
    else
    {
        node->next = pila->top;
        pila->top = node;
    }

    pila->size++;
    return 1;
}

void *Pop(PPila pila)
{
    if (pila->size > 0)
    {
        PNode node = pila->top;
        pila->top = node->next;
        pila->size--;
        return node->dato;
    }

    return NULL;
}

void *SearchByValue(PPila pila, void *dato, int (*cmp)(void *, void *))
{
    PNode node = pila->top;
    while (node != NULL)
    {
        if (cmp(node->dato, dato) == 0)
        {
            return node->dato;
        }
        node = node->next;
    }
    return NULL;
}

void Print(PPila pila)
{
    printf(BOLD "[ " RESET);
    PNode node = pila->top;
    while (node != NULL)
    {
        printf("%s ", node->dato);
        node = node->next;
    }
    printf(BOLD "]" RESET);
}

void insertar()
{
    printf("Dame un nombre a insertar: ");
    char *num = (char *)calloc(20, sizeof(char));
    scanf(" %s", num);
    if (!Push(_Pila, num))
    {
        printf(RED "No se pudo insertar el nombre" RESET);
    }
    else
    {
        printf(GREEN "Nombre insertado correctamente" RESET);
    }

    // Add to file
    {
        FILE *file = fopen("data.txt", "w+");
        if (file == NULL)
        {
            printf(RED "No se pudo abrir el archivo" RESET);
            return;
        }

        PNode node = _Pila->top;
        while (node != NULL)
        {
            fprintf(file, "%s\n", node->dato);
            node = node->next;
        }
        fclose(file);
    }
    system("pause");
}

void eliminar()
{
    char *num = (char *)Pop(_Pila);
    if (_Pila->top == NULL)
    {
        printf(YELLOW "La pila esta vacia" RESET);
        system("pause");
        return;
    }

    if (num == NULL)
    {
        printf(RED "No se pudo eliminar el numero" RESET);
    }
    else
    {
        printf(GREEN "El nombre eliminado es: %s" RESET, num);
        free(num);
    }
    system("pause");
}

int cmp(void *a, void *b)
{
    // sring compare
    return strcmp((char *)a, (char *)b);
}

void buscar()
{
    if (_Pila->top == NULL)
    {
        printf(YELLOW "La pila esta vacia" RESET);
        system("pause");
        return;
    }

    printf("Dame un numero a buscar: ");
    char *num = (char *)calloc(20, sizeof(char));
    if (num == NULL)
    {
        printf(RED "No se pudo crear el numero" RESET);
        return;
    }
    scanf(" %s", num);
    int *num2 = (int *)SearchByValue(_Pila, num, &cmp);
    if (num2 == NULL)
    {
        printf(RED "No se pudo encontrar el numero" RESET);
    }
    else
    {
        printf(GREEN "El nombre se encontro en (%p)" RESET, num2);
    }
    system("pause");
}

void mostrar()
{
    Print(_Pila);
    system("pause");
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    _Pila = (PPila)calloc(1, sizeof(Pila));
    if (_Pila == NULL)
    {
        printf("No se pudo crear la pila");
        return 1;
    }

    { // Read File
        FILE *file = fopen("data.txt", "r");
        if (file == NULL)
        {
            printf(RED "No se pudo abrir el archivo" RESET);
            return 1;
        }

        char *num = (char *)calloc(20, sizeof(char));
        while (fscanf(file, "%s", num) != EOF)
        {
            Push(_Pila, num);
            num = (char *)calloc(20, sizeof(char));
        }
        fclose(file);
    }

    int opcion = 0;
    do
    {
        // clear screen and go to the top left corner
        printf("\033[2J\033[1;1H");

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
    } while (opcion != 0);
}