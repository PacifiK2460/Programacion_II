#include "../bidi.h"

void newBidi(bidi* arr, int COLS, int ROWS){
    arr->arr = malloc(sizeof(int) * (COLS * ROWS));
    if(arr->arr == 0)
        return;

    for(int i = 0; i < COLS * ROWS; i++) arr->arr[i] = 0;
    arr->COLS = COLS;
    arr->ROWS = ROWS;
}

void freeBidi(bidi* arr){
    free(arr->arr);
}

void printBidi(bidi* arr){
    for(int i = 0; i < arr->ROWS; i++){
        for(int j = 0; j < arr->COLS; j++){
            printf("%i ", arr->arr[i*arr->COLS+j]);
        }
        printf("\n");
    }
}

void fillBidi(bidi* arr){
    for(int i = 0; i < arr->ROWS*arr->COLS; i++){
        arr->arr[i] = i;
    }
}