/*
    Martinez Lara Santiago de la cruz
    177685
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Regresamos un randmon entre un rango
int rrand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Llenamos el arreglo con numeros random
void fill(int *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = rrand(1, 26);
    }
}

// Liberamos la memoria
void freearr(int *data)
{
    free(data);
}

// Funcion de clase
void op(int *data, int size)
{
    // Arreglo temporal
    int *temp = (int *)malloc(sizeof(int) * size);
    printf("Normal:\n\t");
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[size - i - 1];
        printf("%-03d ", data[i]);
    }
    printf("\nInvertido:\n\t");
    for (int i = 0; i < size; i++)
    {
        printf("%-03d ", temp[i]);
    }
    printf("\nCaracteres:\n\t");
    for (int i = 0; i < size; i++)
    {
        printf("%-03c ", data[i] + ('A' - 1));
    }
    printf("\nSuma:\n\t");
    for (int i = 0; i < size; i++)
    {
        printf("%-03d ", data[i] + temp[i]);
    }
    printf("\n");
    free(temp);
}

// Imprimimos el arreglo
void print(int *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    // Inicializamos el arreglo y variables
    int size = 10, *data = 0;
    data = (int *)malloc(sizeof(int) * size);

    fill(data, size);
    // print(data, size);
    op(data, size);
    freearr(data);
}