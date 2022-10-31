#include <stdio.h>
#include "../../libs/tree/stree.h"

#include <time.h>

int random_int(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int compare_int(void* a, void* b){
    return *(int*)a - *(int*)b;
}

int main(){
    Tree arbol = {0};
    for(int i = 0; i < 10; i++){
        int *num = (int*)malloc(sizeof(int));
        *num = random_int(0, 100);
        tree_insert(&arbol, num, compare_int);
    }
}