#include <iostream>
#include <time.h>

int rangedrand(int min, int max){
	return min + rand() % (max - min + 1);
}

typedef struct _detalle {
	int id;
	char desc[100];
	char color[100];
	int num;
	char depto[100];
} detalle;

void registrar(detalle* kaslkdnalskdnl){
	kaslkdnalskdnl->id = rangedrand(100,900);
	printf("\nDescripcion:\n\\> ");
	scanf(" %s", &kaslkdnalskdnl->desc);
	printf("Color:\n\\> ");
	scanf(" %s", &dest->color);
	printf("Numero:\n\\> ");
	scanf(" %d", &(dest->num));
	printf("Departamento:\n\\> ");
	scanf(" %s", &dest->depto);
}

void mostrar(detalle* dest){
	printf("%d\t%s\t%s\t%d\t%s\n", dest->id, dest->desc, dest->color, dest->num, dest->depto);
}

int main() {
	
	srand(time(0));
	int numero_de_registros = 5;
	int Registros[numero_de_registros];
	for(int i = 0; i < numero_de_registros; i++){
		registrar(Registros + i);
	}
	
	for(int i = 0; i < numero_de_registros; i++){
		mostrar(Registros + i);
	}
}
