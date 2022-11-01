#include <stdio.h>
#include "../../libs/stree/stree.h"

#include <time.h>

int random_int(int min, int max){
    int n = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    return n;
}

int compare_int(void* a, void* b){
    if(*(int*)a < *(int*)b)
        return -1;
    else if(*(int*)a > *(int*)b)
        return 1;
    else
        return 0;
    
}

int main(){
    srand(time(NULL));
    setbuf(stdout, NULL);
    Tree arbol = {0};
    for(int i = 0; i < 10; i++){
        int *num = (int*)malloc(sizeof(int));
        *num = random_int(0, 100);
        tree_insert(&arbol, num, compare_int);
    }
    for(int i = 0; i < arbol.size; i++){
        int *num = (int*)pop(&arbol);
        printf("%d ", *num);
    }
}