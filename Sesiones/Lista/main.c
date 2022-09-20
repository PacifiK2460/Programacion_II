#include <stdio.h>
#include <time.h>
#include "../../libs/sstring/sstring.h"
#include "../../libs/io/io.h"
#include "../../libs/llist/llist.h"

#define DEBUG 0

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

    int listas = randomRange(3,5);
    #if DEBUG
        printf("Añadiendo %d listas de empleados\n", listas);
    #endif
    for(int i = 0; i < listas; i++) {
        #if DEBUG
            printf("[List %d]: ", i);
        #endif
        addList(lista);
    }
    printList(lista);

    int idDel;

    input("Id del empleado a eliminar: ", evaluarInt(&idDel, stdin));
    for(int i = 0; i < LList_size(lista); i++) {
        for(int j = 0; j < LList_size(LList_get(lista, i)); j++) {
            Empleado* emp = LList_get(LList_get(lista, i), j);
            if(emp->id == idDel) {
                LList_remove_at(LList_get(lista, i), j);
                break;
            }
        }
    }
    printList(lista);

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

    #if DEBUG
        printf("%p\n", list);
    #endif

    int empleados = randomRange(3,5);
    #if DEBUG
        printf("\tAñadiendo %d empleados a la lista\n", empleados);
    #endif
    for(int i = 0; i < empleados; i++) {
        #if DEBUG
            printf("\t\t[Empleado %d]: ",i);
        #endif
        addEmpleado(list);
    }

    LList_add(lista, list);
}

void addEmpleado(LList *lista)
{
    Empleado *empleado = malloc(sizeof(Empleado));
    empleado->id = randomRange(1, 100);
    #if DEBUG
        printf("%p", empleado);
        printf("\tID: %d\n", empleado->id);
    #endif
    LList_add(lista, empleado);
}