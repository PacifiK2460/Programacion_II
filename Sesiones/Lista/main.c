#include <stdio.h>
#include <string.h>

#include "../libs/llist/llist.h"

typedef struct Empleado{
    int id;
    char* nombre;
    char* puesto;
    double salario;
};

int main(){
    LList lista;
    LList_new(&lista);
}