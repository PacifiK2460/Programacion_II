#include <stdio.h>
#include <time.h>
#include "../../libs/sstring/sstring.h"
#include "../../libs/io/io.h"
#include "../../libs/llist/llist.h"

#define NUM 15

typedef struct{
    int id;
    String nombre;
    String puesto;
    double salario;
}Empleado;

void printList(LList* list);

int main(){
    srand(time(0));
    LList* lista = LList_new();
    {// Filling the list with data
        for(int i = 0; i < NUM; i++){
            Empleado* emp = malloc(sizeof(Empleado));

            emp->id = i;
            
            {
                String nombre = malloc(20);
                sprintf(nombre, "Empleado \'%2d\'", i);
                emp->nombre = nombre;
            }
            
            {
                String puesto = malloc(20);
                sprintf(puesto, "Puesto \'%2d\'", i);
                emp->puesto = puesto;
            }

            emp->salario = i;

            LList_add(lista, emp);
        }
    }

    {// Oriinal List
        printf("Lista original:\n");
        printList(lista);
    }

    {// Deleting first
        LList_remove_at(lista, 0);
        printf("Lista sin el primer elemento:\n");
        printList(lista);
    }

    {// Deleting last
        LList_remove_at(lista, LList_size(lista) - 1);
        printf("Lista sin el ultimo elemento:\n");
        printList(lista);
    }

    {// Deleting middle
        LList_remove_at(lista, LList_size(lista) / 2);
        printf("Lista sin el elemento del medio:\n");
        printList(lista);
    }

    {// Deleting random
        int random = rand() % LList_size(lista);
        LList_remove_at(lista, random);
        printf("Lista sin un elemento aleatorio (%d):\n", random);
        printList(lista);
    }

    {// Deleting all
        while(LList_size(lista) > 0){
            Empleado* emp = LList_get(lista, 0);
            LList_remove_at(lista, 0);
            free(emp->nombre);
            free(emp->puesto);
            free(emp);
        }
        free(lista);

        printf("Lista sin elementos:\n");
        printList(lista);
    }
}

void printList(LList* list){
    printf(
        "Ubicacion\tID\tNombre\t\tPuesto\t\tSalario\t\tSiguiente\n"
        );
    for(int i = 0; i < LList_size(list); i++){
        Empleado* emp = LList_get(list, i);
        printf(
            "%p\t%2d\t%s\t%s\t%6.1lf\t\t%p\n",
            emp, emp->id, emp->nombre, emp->puesto, emp->salario, LList_get(list, i+1)
            );
    }
}