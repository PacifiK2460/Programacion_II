#include "llist/llist.h"
#include "io/io.h"
#include "info/info.h"

#include <stdlib.h>
#include <stdio.h>

#include <time.h>

void llenado(LList* list, LList* pares){
        // Hacemos la actividad, dejamos a largo como una variable temporal
    {
        // Creamos de largo aleatorio de entre 6 y 25
        int largo = rand() % 25 + 6;

        for(int i = 0; i < largo; i++){
            // Creamos un numero aleatorio de entre 'a' y 'z'
            // Esta memoria la vamos a dejar "volando", no queremos
            // que se libere, por eso no usamos malloc()
            int *numero = malloc(sizeof(int));
            *numero = 'a' + rand() % ('z' - 'a');

            if(*numero % 2 == 0){
                LList_add(pares, numero);
            }

            // Agregamos el numero a la lista
            LList_add(list, numero);
        }
    }
}

int main(){
    printInfo();

    time(0);

    LList *list = LList_new();
    LList *pares = LList_new();

    llenado(list, pares);

    printf("Vector original, %d elementos: \n", list->size);
    for(int i = 0; i < list->size; i++){
        int *numero = LList_get(list, i);
        printf("%c [%d]\t", *numero, *numero);
    }

    printf("\nVector de elementos pares, %d elementos: \n", pares->size);
    for(int i = pares->size-1; i != 0 ; i--){
        int *numero = LList_get(pares, i);
        printf("%c [%d]\t", *numero, *numero);
    }
  printf("\n");
}