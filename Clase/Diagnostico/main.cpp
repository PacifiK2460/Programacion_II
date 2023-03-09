#include <iostream>
#include <time.h>
#include <stdlib.h>

/*
	Martinez Lara Santiago de la cruz - 177685
	2da vez cursando la materia.
*/

int randgen(int min, int max){
	return rand()%((max+1)-min) + min;
}

void table (int dyn){
	if(dyn){
		int** table = (int**) calloc(5 , sizeof(int*));
		for(int i = 0; i < 5; i++)
			table[i] = (int*) calloc(3 , sizeof(int));
			
		printf("\tDato 1\tDato 2\tDato3\n");
		for(int i = 0; i < 5; i++){
			printf("Fila %i\t", i+1);
			for(int j = 0; j < 3; j++)
			{
				table[i][j] = randgen(0,10);
				printf("%03i\t", table[i][j]);
			}
			printf("\n");
		}
		
		printf("\n\tDato 1\tDato 2\tDato3\tPromedio\n");
		for(int i = 0; i < 5; i++){
			float promedio = 0;
			printf("Fila %i\t", i+1);
			for(int j = 0; j < 3; j++)
			{
				promedio += table[i][j];
				printf("%03i\t", table[i][j]);
			}
			promedio /= 3;
			printf("%03f\n",promedio);
		}		
					
		printf("\n\tDato 1\tDato 2\tDato3\n");
		for(int i = 0; i < 5; i++){
			printf("Fila %i\t", i+1);
			for(int j = 0; j < 3; j++)
			{
				if(table[i][j] % 2 == 0)
					table[i][j] = 100;
				printf("%03i\t", table[i][j]);
			}
			printf("\n");
		}
		getchar();
		getchar();
		
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 3; j++)
				free(table[i][j]);
			free(table[i]);
		}
	} else {
		int table[5][3] = {0};
		
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 3; j++)
			{
				table[i][j] = randgen(0,10);
				printf("%03i\t", table[i][j]);
			}
		}

		printf("\tDato 1\tDato 2\tDato3\n");
		for(int i = 0; i < 5; i++){
			printf("Fila %i\t", i+1);
			for(int j = 0; j < 3; j++)
			{
				table[i][j] = randgen(0,10);
				printf("%03i\t", table[i][j]);
			}
			printf("\n");
		}
		
		printf("\n\tDato 1\tDato 2\tDato3\tPromedio\n");
		for(int i = 0; i < 5; i++){
			float promedio = 0;
			printf("Fila %i\t", i+1);
			for(int j = 0; j < 3; j++)
			{
				promedio += table[i][j];
				printf("%03i\t", table[i][j]);
			}
			promedio /= 3;
			printf("%03f\n",promedio);
		}		
					
		printf("\n\tDato 1\tDato 2\tDato3\n");
		for(int i = 0; i < 5; i++){
			printf("Fila %i\t", i+1);
			for(int j = 0; j < 3; j++)
			{
				if(table[i][j] % 2 == 0)
					table[i][j] = 100;
				printf("%03i\t", table[i][j]);
			}
			printf("\n");
		}
		getchar();
		getchar();	
	}
}

int main() {
	srand(time(NULL));
	
	int opcion = 0;
	while(1)
	{
		system("cls");
		printf(
			"1.- Arreglo Dinamico." "\n"
			"2.- Arreglo Estatico." "\n"
			"3.- Salir" "\n"
			"\\> "
		);
		scanf("%i",&opcion);
		switch(opcion){
			case 1:
					table(1);
				break;
			case 2:
					table(0);
				break;
			case 3:
					return 0;
				break;
			default:
				continue;
		}
		
	}
}
