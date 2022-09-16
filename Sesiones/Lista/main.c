#include <stdio.h>
#include <string.h>

#include "../libs/llist/llist.h"
#include "../libs/io/io.h"
#include "../libs/string/string.h"

typedef struct Empleado{
    int id;
    String* nombre;
    String* puesto;
    double salario;
}Empleado;

void printList(LList *lista);
void addEmpleado(LList *lista);

int main(){
    LList lista;
    LList_new(&lista);

    while (1){
        printf("Presiona CTRL+D para salir, cualquier tecla para agregar un empleado");
        if (getchar() == EOF){
            break;
        }
        addEmpleado(&lista);
    }
    printList(&lista);
}

void printList(LList *lista){
    for(int i = 0; i < LList_size(lista); i++){
        Empleado *empleado = (Empleado*)LList_get(lista, i);
        printf("ID: %d\tNombre: %s\tPuesto: %s\tSalario: %lf", empleado->id, empleado->nombre->str, empleado->puesto->str, empleado->salario);    
    }
}

void addEmpleado(LList *lista){
    Empleado *empleado = malloc(sizeof(Empleado));
    input("ID: ", evaluarInt(&empleado->id, stdin));
    input("Nombre: ", evaluarString(empleado->nombre, stdin));
    input("Puesto: ", evaluarString(empleado->puesto, stdin));
    input("Salario: ", evaluarDouble(&empleado->salario, stdin));
    LList_add(lista, empleado);
}