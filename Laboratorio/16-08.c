#include "info/info.h"
#include <stdlib.h>
#include <stdio.h>

void llenar(int* arreglo, int COLS, int ROWS);
void print(int* arreglo, int COLS, int ROWS);
void sort(int* arreglo, int COLS, int ROWS);

int main(){
    printInfo();
    int arreglo[6][4];
    llenar(arreglo, 4, 6);

    sort(arreglo, 4, 6);

    print(arreglo, 4, 6);

    /*
        rand = 1+rand()%40

        func1(){
            for(itme, index in list){
                item[index] = rand
            }

        sort(){
            sort()
            for(item, index in list){
                temp[cols];
                for(item, index in Item){
                    temp[cols - index] = arr[index];
                }
                for(item, index in Item){
                    temp[index] = arr[cols - index];
                }
            }
        }

        print(){
            for(item in list){
                print(item)
            }
        }
    */
}

void llenar(int* arreglo, int COLS, int ROWS){
    for(int i = 0; i < ROWS*COLS; i++)
        arreglo[i] = 1+rand()%40;
}

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
    for(int i = 0; i < ROWS*COLS; i++){
        for(int j = 0; j < ROWS*COLS; j++){
            if(arreglo[i] < arreglo[j]){
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }

    for(int i = 0; i < ROWS; i+=2){
        int* temp = malloc(COLS * sizeof(int));
        for(int j = 0; j < COLS; j++){
            temp[COLS - j] = arreglo[j];
        }
        for(int j = 0; j < COLS; j++){
            arreglo[j] = temp[COLS - j];
        }
        free(temp);
    }
}