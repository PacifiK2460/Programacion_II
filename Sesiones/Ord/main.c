#include <stdio.h>
#include <stdlib.h>
#include "sort/sort.h"

typedef struct {
    int matricula;
    int edad;
    char nombre[20];
    int carrera[20];
    double calificaciones[3];
}Dato;

int comparar(const void* a, const void* b){
    int A = ((Dato*)a)->matricula;
    int B = ((Dato*)b)->matricula;

    if(A > B) return 1;
    if(A < B) return -1;
    return 0;
}

int main(){
    int n = 3;
    Dato **alumnos;
    int mem[n];
    // Asignamos memoria
    {
        {
            mem[0] = 2;
            mem[1] = 4;
            mem[2] = 3;
        }
        alumnos = malloc(n*sizeof(Dato*));
        for(int i = 0; i < n; i++){
            alumnos[i] = malloc(mem[i]*sizeof(Dato));
        }
    }

    // Asignamos datos
    {
        alumnos[0][0].matricula = 1;
        alumnos[0][1].matricula = 2;
        alumnos[1][0].matricula = 3;
        alumnos[1][1].matricula = 4;
        alumnos[1][2].matricula = 5;
        alumnos[1][3].matricula = 6;
        alumnos[2][0].matricula = 7;
        alumnos[2][1].matricula = 8;
        alumnos[2][2].matricula = 9;

        alumnos[0][0].edad = 20;
        alumnos[0][1].edad = 21;
        alumnos[1][0].edad = 22;
        alumnos[1][1].edad = 23;
        alumnos[1][2].edad = 24;
        alumnos[1][3].edad = 25;
        alumnos[2][0].edad = 26;
        alumnos[2][1].edad = 27;
        alumnos[2][2].edad = 28;

        alumnos[0][0].nombre = "Juan";
        alumnos[0][1].nombre = "Pedro";
        alumnos[1][0].nombre = "Maria";
        alumnos[1][1].nombre = "Luis";
        alumnos[1][2].nombre = "Ana";
        alumnos[1][3].nombre = "Jose";
        alumnos[2][0].nombre = "Luisa";
        alumnos[2][1].nombre = "Rosa";
        alumnos[2][2].nombre = "Lorena";
        
    }

    // Impresión de datos antes de ordenas
    {
        printf("### ANTES DE ORDENAR");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < mem[i]; j++){
                printf("[%d][%d]\t%d\t%s\t%d\n", i, j, alumnos[i][j].matricula, alumnos[i][j].nombre, alumnos[i][j].edad);
            }
            printf("\n");
        }
    }

    // Ordenado de alumnos segun su edad
    for(int i = 0; i < n; i++){
        mergesort(alumnos[i],mem[i], comparar);
    }

    // Impresión de datos
    {
        printf("### DESPUES DE ORDENAR");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < mem[i]; j++){
                printf("[%d][%d]\t%d\t%s\t%d\n", i, j, alumnos[i][j].matricula, alumnos[i][j].nombre, alumnos[i][j].edad);
            }
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}