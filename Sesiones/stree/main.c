#include <stdio.h>
#include "../../libs/stree/stree.h"

#include <time.h>

typedef struct {
    int integer;
    float flotant;
} Nodo;

void print(void *nodo) {
    Nodo* data = (Nodo*) nodo;

    printf("%d, %f\n", data->integer, data->flotant);
}

int random_int(int min, int max){
    int n = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    return n;
}

int compare_int(void* a, void* b){
    Nodo* node_a = (Nodo*)a;
    Nodo* node_b = (Nodo*)b;

    if(node_a->integer < node_b->integer)
        return -1;
    else if(node_a->integer > node_b->integer)
        return 1;
    else
        return 0;
}

int main(){
    srand(time(NULL));
    setbuf(stdout, NULL);
    Tree arbol = {0};
    for(int i = 0; i < 10; i++){
        Nodo* nodo = malloc(sizeof(Nodo));

        nodo->integer = random_int(0, 100);
        nodo->flotant = (float)random_int(0, 100);
        
        tree_insert(&arbol, nodo, compare_int);
    }

    tree_print(&arbol, print);

    int id;
    printf("\nIngrese un id a modificar: ");
    scanf("%d", &id);

    int new_flotant;
    printf("Ingrese un nuevo flotante: ");
    scanf("%d", &new_flotant);

    Nodo* to_modify = tree_search(&arbol, &id, compare_int);    

    to_modify->flotant = new_flotant;

    tree_print(&arbol, print);
}