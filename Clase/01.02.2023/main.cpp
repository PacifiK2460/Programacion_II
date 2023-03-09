#include <iostream>
#include <time.h>

int rangedrand(int min, int max){
 return min + rand() % (max - min + 1);
}

void evaluar(int encuesta[10][3], int encuestas, int productos){
	int i;
	for(i = 0; i < encuestas; i++){
		int j;
		for(j = 0; j < productos; j++){
			encuesta[i][j] = rangedrand(1,4);
		}
	}
}

void imprimir(int encuesta[10][3], int encuestas, int productos){
	int i;
	printf("Encuesta\tA\tB\tC\n");
	for(i = 0; i < encuestas; i++){
		printf("%i\t\t\%i\t%i\t%i\n",i, encuesta[i][0],encuesta[i][1],encuesta[i][2]);
	}
}

void estadisticas(int encuesta[10][3], int encuestas, int productos){
	int i;
	int ex = 0,bn = 0,re = 0,nm = 0;
	for(i = 0; i < encuestas; i++){
		int j;
		for(j = 0; j < productos; j++){
			switch(encuesta[i][j]) {
				case 1:
					ex++;
					break;
				case 2:
					bn++;
					break;
				case 3:
					re++;
					break;
				case 4:
					nm++;
					break;
				}
		}
	}
	printf("Excelentes: %d\n", ex);
	printf("Bueno: %d\n", bn);
	printf("Regular: %d\n", re);
	printf("No me gusto: %d\n", nm);
}

int main(){
	srand(time(0));
	int encuestas = 10, productos = 3;
	int encuesta[10][3];
	evaluar( encuesta, encuestas, productos);
	imprimir(encuesta, encuestas, productos);
	estadisticas(encuesta, encuestas, productos);
}
