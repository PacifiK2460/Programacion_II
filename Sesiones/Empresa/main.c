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
    Empresa empresa;
    Departamento departamento;
    Empleado empleado;
} Relacion;

int writeRelacion(Relacion relacion, FILE* stream){
    if(stream == 0) return -1;

    fprintf(stream,"%i\n"
    "%i\n"
    "%s\n"

    "%i\n"
    "%s\n"
    "%s\n"
    
    "%i\n"
    "%s\n"
    "%lf\n",
    
    relacion.idRelación,
    relacion.empresa->idEmpresa,
    relacion.empresa->RazonSocial.str,
    relacion.departamento->idDepartamento,
    relacion.departamento->nombre.str,
    relacion.departamento->projecto.str,
    relacion.empleado->idEmpleado,
    relacion.empleado->nombre.str,
    relacion.empleado->sueldo);

    return 1;
}

int readRelacion(Relacion* relacion, FILE* stream){
    if(stream == 0) return -1;

    if( evaluarInt(&relacion->idRelación, stream) == -1) return 0;
    if( evaluarInt(&relacion->empresa->idEmpresa, stream) == -1) return 0;
    if( evaluarString(&relacion->empresa->RazonSocial, stream) == -1) return 0;
    if( evaluarInt(&relacion->departamento->idDepartamento, stream) == -1) return 0;
    if( evaluarString(&relacion->departamento->nombre, stream) == -1) return 0;
    if( evaluarString(&relacion->departamento->projecto, stream) == -1) return 0;
    if( evaluarInt(&relacion->empleado->idEmpleado, stream) == -1) return 0;
    if( evaluarString(&relacion->empleado->nombre, stream) == -1) return 0;
    if( evaluarDouble(&relacion->empleado->sueldo, stream) == -1) return 0;

    return 1;
}

int main(){
    int N = 0;
    input("N: ", evaluarInt(&N, stdin));
    Relacion *relacion = malloc( N * sizeof(Relacion));
    if(relacion == 0) return -1;

    for(int i = 0; i < N; i++){
        input("idRelación: ", evaluarInt(&relacion[i].idRelación, stdin));
        input("idEmpresa: ", evaluarInt(&relacion[i].empresa->idEmpresa, stdin));
        input("RazonSocial: ", evaluarString(&relacion[i].empresa->RazonSocial, stdin));
        input("idDepartamento: ", evaluarInt(&relacion[i].departamento->idDepartamento, stdin));
        input("nombre: ", evaluarString(&relacion[i].departamento->nombre, stdin));
        input("projecto: ", evaluarString(&relacion[i].departamento->projecto, stdin));
        input("idEmpleado: ", evaluarInt(&relacion[i].empleado->idEmpleado, stdin));
        input("nombre: ", evaluarString(&relacion[i].empleado->nombre, stdin));
        input("sueldo: ", evaluarDouble(&relacion[i].empleado->sueldo, stdin));
    }


    printf("\nDatos obtenidos:");
    for(int i = 0; i < N;  i++){
        printf("\nidRelación: %i", relacion[i].idRelación);
        printf("\nidEmpresa: %i", relacion[i].empresa->idEmpresa);
        printf("\nRazonSocial: %i", relacion[i].empresa->RazonSocial.str);
        printf("\nidDepartamento: %i", relacion[i].departamento->idDepartamento);
        printf("\nnombre: %i", relacion[i].departamento->nombre.str);
        printf("\nprojecto: %i", relacion[i].departamento->projecto.str);
        printf("\nidEmpleado: %i", relacion[i].empleado->idEmpleado);
        printf("\nnombre: %i", relacion[i].empleado->nombre.str);
        printf("\nsueldo: %i", relacion[i].empleado->sueldo);
    }



    FILE* stream = fopen("data.txt", "w");
    if(stream == 0) return -1;
    writeRelacion(*relacion, stream);
    return 0;
}