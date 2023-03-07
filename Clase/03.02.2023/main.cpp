#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rangedrand(int min, int max){
	return min + rand() % (max - min + 1);
}

int* uni_crear(int n){
	int* temp = (int*)malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n; i++){
		temp[i] = rangedrand(20,50);
	}
	
	return temp;
}

int** bidi_crear(int n, int m){
	int** temp = (int**)malloc(n * sizeof(int*));
	int i;
	for(i = 0; i < n; i++){
		temp[i] = (int*)malloc(m * sizeof(int));
		int j;
		for(j = 0; j < m; j++){
			temp[i][j] = rangedrand(70,90);
		}
	}
	return temp;
}

void uni_promedio(int* data, int n){
	int i;
	float prom = 0;
	int m = 0;
	for(i = 0; i < n; i++){
		printf("%d ", data[i]);
		if(data[i] % 3 == 0){
			prom += data[i];
			m++;
		}
	}
	printf("\n %.2f \n", prom / n);
}

void bidi_promedio(int** data, int n, int m){
	int i,j,k = 0;
	float prom = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ", data[i][j]);
			if(data[i][j] % 7 == 0){
				prom += data[i][j];
				k++;
			}
		}
		printf("\n");
	}
	printf("\n %.2f \n", prom / k);
}

int main() {
	srand(time(0));
	
	while(1){
		{ // Unidimensional
			int n;
			printf("Elementos:\n\\> ");
			scanf("%d", &n);
		
			int* uni = uni_crear(n);
			uni_promedio(uni, n);
			free(uni);
		}
		
		{ // Bidimensional
			int n,m;
			printf("Elementos:\n\\> ");
			scanf("%d %d", &n, &m);
			
			int** bidi = bidi_crear(n,m);
			bidi_promedio(bidi,n,m);
			int i;
			for(i = 0; i < n; i++){
				free(bidi[i]);
			}
			free(bidi);
		}
		
		printf("Continuar: [Y/N]\n\\> ");
		char t;
		scanf(" %c", &t);
		if(t != 'Y')
			break;
	}
}
