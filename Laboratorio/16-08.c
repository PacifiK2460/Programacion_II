#include "info/info.h"
#include <stdlib.h>
#include <stdio.h>

//PROTOTIPOS
void llenar(int* arreglo, int COLS, int ROWS);
void print(int* arreglo, int COLS, int ROWS);
void sort(int* arreglo, int COLS, int ROWS);

int main(){
    printInfo();
    int arreglo[6][4];
    llenar(arreglo, 4, 6);

    sort(arreglo, 4, 6);

    print(arreglo, 4, 6);
}

//LENO EL ARREGLO CON DATOS ALEATORIOS
void llenar(int* arreglo, int COLS, int ROWS){
    for(int i = 0; i < ROWS*COLS; i++)
        arreglo[i] = 1+rand()%40;
}

//IMPRIMO CADA ELEMNTO
void print(int* arreglo, int COLS, int ROWS){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%i ", arreglo[i*COLS+j]);
        }
        printf("\n");
    }
}

void sort(int* arreglo, int COLS, int ROWS){
    //sort;

    //sort array
    //VOY A CADA ITEM
    for(int i = 0; i < ROWS*COLS; i++){
      // SI ESTE ES MENOR AL SIG LOS CAMBIO
        for(int j = 0; j < ROWS*COLS; j++){
            if(arreglo[i] < arreglo[j]){
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }

    // UNA VEZ ORDENADO, CADA DOS FILAS LOS CAMBIO
    for(int i = 0; i < ROWS; i+=2){
        int* temp = malloc(COLS * sizeof(int));

        //invert array
      // COPIO EN UN ARREGLO TEMPORAL
        for(int j = 0; j < COLS; j++){
            temp[j] = arreglo[i*COLS+j];
        }

      //LOS INTERCAMBIO DELANTE POR DETRAS
        for(int j = 0; j < COLS; j++){
            arreglo[i*COLS+j] = temp[COLS-j-1];
        }

        free(temp);
    }
}