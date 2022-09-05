#include <stdio.h>
#include "../../libs/io/io.h"
#include "../../libs/string/string.h"


typedef struct{
    int id;
    String* nombre;
    double ingreso;
    int articulos;
    int estadoCivil;
} trabajador;

// sort workers by income
void sort(trabajador* trabajadores, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(trabajadores[i].ingreso > trabajadores[j].ingreso){
                trabajador temp = trabajadores[i];
                trabajadores[i] = trabajadores[j];
                trabajadores[j] = temp;
            }
        }
    }
}

int main(){
    trabajador** trabajadores;

    int filas;
    input("Ingrese el numero de listas: ", evaluarInt(&filas, stdin));

    trabajadores = (trabajador**)malloc(filas * sizeof(trabajador*));

    int NCols[filas];
    for(int i = 0; i < filas; i++){
        input("Ingrese el numero de trabajadores: ", evaluarInt(&NCols[i], stdin));
        trabajadores[i] = (trabajador*)malloc(NCols[i] * sizeof(trabajador));

        for(int j = 0; j < NCols[i]; j++){
            input("Ingrese el id: ", evaluarInt(&trabajadores[i][j].id, stdin));
            //input("Ingrese el nombre: ", evaluarString(&trabajadores[i][j].nombre, stdin));
            input("Ingrese el ingreso: ", evaluarDouble(&trabajadores[i][j].ingreso, stdin));
            input("Ingrese el numero de articulos: ", evaluarInt(&trabajadores[i][j].articulos, stdin));
            input("Ingrese el estado civil: ", evaluarInt(&trabajadores[i][j].estadoCivil, stdin));
        }

        sort(trabajadores[i], NCols[i]);
    }

    printf("Datos Obtenidos\n");
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < NCols[i]; j++){
            double comision;
            double total;

            if(trabajadores[i][j].estadoCivil == 0){
                if(trabajadores[i][i].articulos < 100){
                    comision = trabajadores[i][j].ingreso * 0.01;
                } else if (trabajadores[i][j].articulos >= 100 && trabajadores[i][j].articulos <= 250){
                    comision = trabajadores[i][j].ingreso * 0.02;
                } else if (trabajadores[i][j].articulos >= 251 && trabajadores[i][j].articulos <= 350){
                    comision = trabajadores[i][j].ingreso * 0.03;
                } else if(trabajadores[i][j].articulos > 350){
                    comision = trabajadores[i][j].ingreso * 0.04;
                }
            } else {
                if(trabajadores[i][i].articulos < 140){
                    comision = trabajadores[i][j].ingreso * 0.015;
                } else if (trabajadores[i][j].articulos >= 140 && trabajadores[i][j].articulos <= 294){
                    comision = trabajadores[i][j].ingreso * 0.035;
                } else if (trabajadores[i][j].articulos > 294){
                    comision = trabajadores[i][j].ingreso * 0.055;
                }
            }

            total = trabajadores[i][j].ingreso + comision;

           printf("[%d][%d]\t",
                i, j);
            printf("ID: %d\t Ingreso: %lf\tNumero de Articulos: %d\tComision: %lf\tTotal: %lf",
                trabajadores[i][j].id, trabajadores[i][j].ingreso,trabajadores[i][j].articulos, comision,total);
          if(trabajadores[i][j].estadoCivil == 0){
            printf("\tSoltero\n");
          } else{
            printf("\tCasado\n");
          }
        }
        printf("\n");
    }

}
