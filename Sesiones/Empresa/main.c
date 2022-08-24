#include "io/io.h"
#include "string/string.h"
#include "llist/llist.h"
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

int writeRelacion(Relacion relacion, FILE *stream)
{
    if (stream == 0)
        return -1;

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

int readRelacion(Relacion *relacion, FILE *stream)
{
    if (stream == 0)
        return -1;

    if (evaluarInt(&(relacion->idRelación), stream) == -1)
        return -1;
    if (evaluarInt(&(relacion->empresa.idEmpresa), stream) == -1)
        return -1;
    if (evaluarString(&(relacion->empresa.RazonSocial), stream) == -1)
        return -1;
    if (evaluarInt(&(relacion->departamento.idDepartamento), stream) == -1)
        return -1;
    if (evaluarString(&(relacion->departamento.nombre), stream) == -1)
        return -1;
    if (evaluarString(&(relacion->departamento.projecto), stream) == -1)
        return -1;
    if (evaluarInt(&(relacion->empleado.idEmpleado), stream) == -1)
        return -1;
    if (evaluarString(&(relacion->empleado.nombre), stream) == -1)
        return -1;
    if (evaluarDouble(&(relacion->empleado.sueldo), stream) == -1)
        return -1;

    return 1;
}

int main()
{
    int N = 0;
    input("N: ", evaluarInt(&N, stdin));

    int Js[N];

    Relacion **relacion = malloc(N * sizeof(Relacion *));
    for (int i = 0; i < N; i++)
    {
        int J = 0;
        input("J: ", evaluarInt(&J, stdin));

        Js[i] = J;
        relacion[i] = malloc(J * sizeof(Relacion));
    }

    if (relacion == 0)
        return -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < Js[i]; j++)
        {
            input("idRelación: ", evaluarInt(&relacion[i][j].idRelación, stdin));
            input("idEmpresa: ", evaluarInt(&relacion[i][j].empresa.idEmpresa, stdin));
            input("RazonSocial: ", evaluarString(&relacion[i][j].empresa.RazonSocial, stdin));
            input("idDepartamento: ", evaluarInt(&relacion[i][j].departamento.idDepartamento, stdin));
            input("nombre: ", evaluarString(&relacion[i][j].departamento.nombre, stdin));
            input("projecto: ", evaluarString(&relacion[i][j].departamento.projecto, stdin));
            input("idEmpleado: ", evaluarInt(&relacion[i][j].empleado.idEmpleado, stdin));
            input("nombre: ", evaluarString(&relacion[i][j].empleado.nombre, stdin));
            input("sueldo: ", evaluarDouble(&relacion[i][j].empleado.sueldo, stdin));
        }
    }

    printf("\nDatos obtenidos:");
    FILE *stream = fopen("data.txt", "w");
    if (stream == 0)
        return -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < Js[i]; j++)
        {
            printf("\nidRelación: %i", relacion[i][j].idRelación);
            printf("\nidEmpresa: %i", relacion[i][j].empresa.idEmpresa);
            printf("\nRazonSocial: %s", relacion[i][j].empresa.RazonSocial.str);
            printf("\nidDepartamento: %i", relacion[i][j].departamento.idDepartamento);
            printf("\nnombre: %s", relacion[i][j].departamento.nombre.str);
            printf("\nprojecto: %s", relacion[i][j].departamento.projecto.str);
            printf("\nidEmpleado: %i", relacion[i][j].empleado.idEmpleado);
            printf("\nnombre: %s", relacion[i][j].empleado.nombre.str);
            printf("\nsueldo: %fl", relacion[i][j].empleado.sueldo);

            if (writeRelacion(relacion[i][j], stream) == -1)
            {
                printf("\n[FATAL] Error al escribir en el archivo, parando para prevenir corrupcion de datos");
                fclose(stream);
                return -1;
            }

            free(relacion[i][j].empresa.RazonSocial.str);
            free(relacion[i][j].departamento.nombre.str);
            free(relacion[i][j].departamento.projecto.str);
            free(relacion[i][j].empleado.nombre.str);
        }
        free(relacion[i]);
    }
    fclose(stream);
    free(relacion);

    return 0;
}