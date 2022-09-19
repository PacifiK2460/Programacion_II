#include <stdio.h>
#include <time.h>
#include "../../libs/sstring/sstring.h"
#include "../../libs/io/io.h"
#include "../../libs/llist/llist.h"

// random ranged number generator
int randomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
} 

typedef struct Empleado
{
    int id;
    String nombre;
    String puesto;
    double salario;
} Empleado;

void printList(LList *lista);
void addEmpleado(LList *lista);
void addList(LList *lista);

int main()
{
    srand(time(0));
    LList* lista = LList_new();

    printf("Base list: %p\n", lista);

    int listas = randomRange(3,5);
    printf("Añadiendo %d listas de empleados\n", listas);
    for(int i = 0; i < listas; i++) {
        printf("[List %d]: ", i);
        addList(lista);
    }
    printList(lista);

    int temp = 52;
    LList_add_at(lista, &temp, 0 );

    printf("%d", (int*)Llist_get_at(lista, 0));
}

void printList(LList *lista)
{
    printf("\nBASE: %p\n", lista);
    // Print pointer data and next pointer
    for (int i = 0; i < LList_size(lista); i++)
    {
        LList* list = LList_get(lista, i);
        printf("[List 0]: %p -> %p\n", list, LList_get(lista, i+1));
        printf("\t%d empleados\n", LList_size(list));
        for (int j = 0; j < LList_size(list); j++)
        {
            Empleado* empleado = LList_get(list, j);
            printf("\t\t[Empleado %d] (ID = %2d): %p -> %p)\n", j, empleado->id, empleado, LList_get(list, j+1));
        }
    }
}

void addList(LList *lista)
{
    LList* list = LList_new();

    printf("%p\n", list);

    int empleados = randomRange(3,5);
    printf("\tAñadiendo %d empleados a la lista\n", empleados);
    for(int i = 0; i < empleados; i++) {
        printf("\t\t[Empleado %d]: ",i);
        addEmpleado(list);
    }

    LList_add(lista, list);
}

void addEmpleado(LList *lista)
{
    Empleado *empleado = malloc(sizeof(Empleado));
    printf("%p", empleado);
    empleado->id = randomRange(1, 100);
    printf("\tID: %d\n", empleado->id);
    LList_add(lista, empleado);
}