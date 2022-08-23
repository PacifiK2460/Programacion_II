#include "io/io.h"
#include "string/string.h"
#include "llist/llist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Empresa{
    int idEmpresa;
    String RazonSocial;
} Empresa;

typedef struct Departamento{
    int idDepartamento;
    String nombre;
    String projecto;
} Departamento;

typedef struct Empleado{
    int idEmpleado;
    String nombre;
    double sueldo;
} Empleado;

typedef struct Relacion{
    int idRelación;
    Empresa* empresa;
    Departamento* departamento;
    Empleado* empleado;
} Relacion;

int main(){
    Relacion *relacion = malloc(sizeof(Relacion));
    if(relacion == 0) return -1;

    relacion->empleado = malloc(sizeof(Empleado));
    relacion->departamento = malloc(sizeof(Departamento));
    relacion->empresa = malloc(sizeof(Empresa));

    if(relacion->empleado == 0 || relacion->departamento == 0 || relacion->empresa == 0) return -1;

    input("Id de la relación: ", evaluarInt(&relacion->idRelación, stdin));
    input("Id de la empresa: ", evaluarInt(&relacion->empresa->idEmpresa, stdin));
    input("Razon social de la empresa: ", evaluarString(&relacion->empresa->RazonSocial, stdin));

    input("Id del departamento: ", evaluarInt(&relacion->departamento->idDepartamento, stdin));
    input("Nombre del departamento: ", evaluarString(&relacion->departamento->nombre, stdin));
    input("Projecto del departamento: ", evaluarString(&relacion->departamento->projecto, stdin));

    input("Id del empleado: ", evaluarInt(&relacion->empleado->idEmpleado, stdin));
    input("Nombre del empleado: ", evaluarString(&relacion->empleado->nombre, stdin));
    input("Sueldo del empleado: ", evaluarDouble(&relacion->empleado->sueldo, stdin));

    printf("Datos obtenidos: \n");
    printf("Id de la relación: %i\n", relacion->idRelación);
    printf("Id de la empresa: %i\n", relacion->empresa->idEmpresa);
    printf("Razon social de la empresa: %s\n", relacion->empresa->RazonSocial.str);
    printf("Id del departamento: %i\n", relacion->departamento->idDepartamento);
    printf("Nombre del departamento: %s\n", relacion->departamento->nombre.str);
    printf("Projecto del departamento: %s\n", relacion->departamento->projecto.str);|
    printf("Id del empleado: %i\n", relacion->empleado->idEmpleado);
    printf("Nombre del empleado: %s\n", relacion->empleado->nombre.str);
    printf("Sueldo del empleado: %f\n", relacion->empleado->sueldo);

    retuirn 0;
}