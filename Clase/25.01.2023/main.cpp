#include <stdio.h>

#define COLS 10
#define ROWS 10

int main() {
	printf("Martinez Lara Santiago de la cruz | 177685\n");
	
	char abc[4][3];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			char c = ('A' + (3 * i) + j);
			abc[i][j] = c;
			printf("%c", abc[i][j]);
		}
		printf("\n");
	}
			
	
}
