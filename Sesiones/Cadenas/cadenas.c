#include "io/io.h"

int main(){
    int N;
    input("Ingrese el numero de Filas: ", evaluarInt(&N, stdin));

    int **filas = malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
      printf("\nFila: %i.\n", i);
      int M;
      input("Ingrese el numero de columnas: ", evaluarInt(&M, stdin));
      filas[i] = malloc((M + 1) * sizeof(int));
      int suma = 0;
      for(int j = 0; j < M; j++){
        printf("Columna: %i.\n", j);
        input("Ingrese el numero a guardar: ", evaluarInt(&(filas[i][j]), stdin));
        suma += filas[i][j];
      }

      filas[i][M] = suma;

      printf("Resultados: ");
      for(int j = 0; j < M+1; j++){
        printf("%i ", filas[i][j]);
      }
      printf("\n");
    }
}