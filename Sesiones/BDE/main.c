#include "io/io.h"
#include "string/string.h"

#include <stdio.h>
#include <stdlib.h>


typedef struct Empresa
{
    int idEmpresa;
    String RazonSocial;
} Empresa;

typedef struct Departamento
{
    int idDepartamento;
    String nombre;
    String projecto;
} Departamento;

typedef struct Empleado
{
    int idEmpleado;
    String nombre;
    double sueldo;
} Empleado;

typedef struct Relacion
{
    int idRelación;
    Empresa empresa;
    Departamento departamento;
    Empleado empleado;
} Relacion;

int writeRelacion(Relacion relacion, FILE *stream, int FORMAT)
{
    if (stream == 0)
        return -1;

    if (FORMAT == 0){
        fprintf(stream, "%i\n"
                        "%i\n"
                        "%s\n"

                        "%i\n"
                        "%s\n"
                        "%s\n"

                        "%i\n"
                        "%s\n"
                        "%lf\n",

                relacion.idRelación,
                relacion.empresa.idEmpresa,
                relacion.empresa.RazonSocial.str,
                relacion.departamento.idDepartamento,
                relacion.departamento.nombre.str,
                relacion.departamento.projecto.str,
                relacion.empleado.idEmpleado,
                relacion.empleado.nombre.str,
                relacion.empleado.sueldo);
        return 1;
    }

    fprintf(stream, "Relacion IdRelacion: %i\n"
                "Relacion Empresa idEmpresa: %i\n"
                "Relacion Empresa RazonSocial: %s\n"

                "Relacion Departamento idDepartamento: %i\n"
                "Relacion Departamento Nombre: %s\n"
                "Relacion Departamento Projecto: %s\n"

                "Relacion Empleado idEmpleado: %i\n"
                "Relacion Empleado Nombre: %s\n"
                "Relacion Empleado Sueldo: %lf\n",

        relacion.idRelación,
        relacion.empresa.idEmpresa,
        relacion.empresa.RazonSocial.str,
        relacion.departamento.idDepartamento,
        relacion.departamento.nombre.str,
        relacion.departamento.projecto.str,
        relacion.empleado.idEmpleado,
        relacion.empleado.nombre.str,
        relacion.empleado.sueldo);


    return 1;
}

int inputRelacion(Relacion* relacion){
    input("idRelación: ", evaluarInt(&relacion->idRelación,stdin));
    input("idEmpresa: ", evaluarInt(&relacion->empresa.idEmpresa,stdin));
    input("RazonSocial: ", evaluarString(&relacion->empresa.RazonSocial,stdin));
    input("idDepartamento: ", evaluarInt(&relacion->departamento.idDepartamento,stdin));
    input("nombre: ", evaluarString(&relacion->departamento.nombre,stdin));
    input("projecto: ", evaluarString(&relacion->departamento.projecto,stdin));
    input("idEmpleado: ", evaluarInt(&relacion->empleado.idEmpleado,stdin));
    input("nombre: ", evaluarString(&relacion->empleado.nombre,stdin));
    input("sueldo: ", evaluarDouble(&relacion->empleado.sueldo,stdin));

    return 1;
}

int main(){
    // Sesiones
    int N = 0;
    input("Ingrese el numero de sesiones: ", evaluarInt(&N,stdin) );
    Relacion **dato = (Relacion**)malloc(N * sizeof(Relacion*));

    // Relaciones de cada sesion
    int M[N] = {0};
    for(int i = 0; i < N; i++){
        input("Ingrese el numero de relaciones: ", evaluarInt(&M[i],stdin) );
        dato[i] = (Relacion*)malloc(M[i] * sizeof(Relacion));
    }

    // Relacion Input
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M[i]; j++){
            inputRelacion(&dato[i][j]);
        }
    }

    // Relacion Output
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M[i]; j++){
            writeRelacion(dato[i][j], stdout,1);
        }
    }
    
    // Memory free
    {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M[i]; j++){
                free(dato[i][j].empleado.nombre.str);
                free(dato[i][j].departamento.nombre.str);
                free(dato[i][j].departamento.projecto.str);
                free(dato[i][j].empresa.RazonSocial.str);
            }
            free(dato[i]);
        }
        free(dato);
    }
    return 0;

}