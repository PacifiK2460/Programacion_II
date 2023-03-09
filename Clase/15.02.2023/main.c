#include<stdio.h>
#include<stdlib.h>

int print_array(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}

int get_array(int *array, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
}

int bubble_sort(int *array, int size){
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){
    int size = 6;
    int array1[6];
    get_array(array1, size);
    bubble_sort(array1, size);
    print_array(array1, size);
}