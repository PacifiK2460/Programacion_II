#include "llist/llist.h"
#include "io/io.h"
#include "info/info.h"

#include <stdlib.h>
#include <stdio.h>

#include <time.h>

int main(){
    printInfo();

    time(0);

    LList *list = LList_new();
    LList *pares = LList_new();

    // Hacemos la actividad, dejamos a largo como una variable temporal
    {
        // Creamos de largo aleatorio de entre 6 y 25
        int largo = rand() % 25 + 6;

        for(int i = 0; i < largo; i++){
            // Creamos un numero aleatorio de entre 'a' y 'z'
            // Esta memoria la vamos a dejar "volando", no queremos
            // que se libere, por eso no usamos malloc()
            int *numero = malloc(sizeof(int));
            *numero = rand() % 'a' + 'a';

            if(*numero % 2 == 0){
                LList_add(pares, numero);
            }

            // Agregamos el numero a la lista
            LList_add(list, numero);
        }
    }

    printf("Vector original, %d elementos: \n", list->size);
    for(int i = 0; i < list->size; i++){
        int *numero = LList_get(list, i);
        printf("%c [%c]\t", *numero, *numero);
    }

    printf("\nVector de elementos pares, %d elementos: \n", pares->size);
    for(int i = pares->size; i >= 0 ; i--){
        int *numero = LList_get(pares, i);
        printf("%c [%c]\t", *numero, *numero);
    }
}