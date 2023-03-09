#include <stdio.h>

#define ArraySize 10

int rangedrand(int min, int max){
    return rand() % (max - min + 1) + min;
}

void fillArray(int* array, int size){
    for(int i = 0; i < size; i++){
        array[i] = rangedrand(0, 100);
    }
}

void showArray(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selectionSort(int* array, int size){
    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            if(array[j] > array[min]){
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void search(int* array, int size, int value){
    int i = 0;
    while(i < size && array[i] != value){
        i++;
    }
    if(i < size){
        printf("El valor %d se encuentra en la posicion %d", value, i);
    }else{
        printf("El valor %d no se encuentra en el arreglo", value);
    }
}

int main(){
    printf("Martinez Lara Santiago de la cruz, 177685\n");

    int* array = (int*) malloc(ArraySize * sizeof(int));
    fillArray(array, ArraySize);
    printf("Array inicial: \n"")
    showArray(array, ArraySize);

    selectionSort(array, ArraySize);
    printf("Array ordenado: \n");
    showArray(array, ArraySize);
}