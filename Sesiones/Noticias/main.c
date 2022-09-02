#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "io/io.h"
#include "string/string.h"

enum clasificacion {
    social = 1,
    deportiva,
    economica,
    cultural,
    cientifica
};

enum tipo{
    nacional = 1,
    internacional
};


typedef struct {
    int iDNoticia;
    int clasificacion;
    int tipo;
    String noticia;
    String encabezado;
    String nombreAutor;
} Noticia;

void printNoticia(Noticia* registro){
    // imprimimos la noticia
    printf("\t\tID: %d\n", registro->iDNoticia);

    switch(registro->clasificacion){
        case social:
            printf("\t\tClasificacion: Social\n");
            break;
        case deportiva:
            printf("\t\tClasificacion: Deportiva\n");
            break;
        case economica:
            printf("\t\tClasificacion: Economica\n");
            break;
        case cultural:
            printf("\t\tClasificacion: Cultural\n");
            break;
        case cientifica:
            printf("\t\tClasificacion: Cientifica\n");
            break;
    }
    switch(registro->tipo){
        case nacional:
            printf("\t\tTipo: Nacional\n");
            break;
        case internacional:
            printf("\t\tTipo: Internacional\n");
            break;
    }
    
    printf("\t\tNoticia: %s\n", registro->noticia.str);
    printf("\t\tEncabezado: %s\n", registro->encabezado.str);
    printf("\t\tNombre del autor: %s\n", registro->nombreAutor.str);
}

void sortd(Noticia* registro, int registros){
    // insertion sort
    int i, j;
    Noticia key;
    for(i = 1; i < registros; i++){
        key = registro[i];
        j = i - 1;
        while(j >= 0 && registro[j].iDNoticia > key.iDNoticia){
            registro[j + 1] = registro[j];
            j = j - 1;
        }
        registro[j + 1] = key;
    }
    return;
}

int main(){
    srand(time(NULL));
    Noticia** registro;
    int nRegistros;
    input("Introduzca el numero de registros: ", evaluarInt(&nRegistros, stdin));
    registro = (Noticia**) malloc(nRegistros * sizeof(Noticia*));
    int registros[nRegistros];

    for(int i = 0; i < nRegistros; i++){
        input("Numero de noticia: ", evaluarInt(&registros[i], stdin));
        registro[i] = (Noticia*) malloc(sizeof(Noticia));

        for(int j = 0; j < registros[i]; j++){
            printf("Introduzca la noticia %d:  (del la lista %d) ", j+1, i+1);

            registro[i][j]->iDNoticia = rand() % 50 + j;

            input("Introduzca la noticia: ", evaluarString(&registro[i][j]->noticia, stdin));
            input("Introduzca el encabezado: ", evaluarString(&registro[i][j]->encabezado, stdin));
            input("Introduzca el nombre del autor: ", evaluarString(&registro[i][j]->nombreAutor, stdin));
            
            printf("Clasificaciones disponibles: \n");
            printf("1. Social\n");
            printf("2. Deportiva\n");
            printf("3. Economica\n");
            printf("4. Cultural\n");
            printf("5. Cientifica\n");
            input("Introduzca la clasificacion [1 - 5]: ", evaluarInt(&registro[i][j]->clasificacion, stdin));
            
            printf("Tipos disponibles: \n");
            printf("1. Nacional\n");
            printf("2. Internacional\n");
            input("Introduzca el tipo [1 - 2]: ", evaluarInt(&registro[i][j]->tipo, stdin));
        }
    }

    printf("Noticias no ordenadas: \n");
    for(int i = 0; i < nRegistros; i++){
        printf("Listado %d: \n", i+1);
        for(int j = 0; j < registros[i]; j++){
            printf("\tNoticia %d: \n", j+1);
            printNoticia(registro[j]);
        }
    }

    // Preguntamos por la noticia  mostrar
    while(1){
        int noticia;
        input("Introduzca el numero de noticia a mostrar, 0 para salir: ", evaluarInt(&noticia, stdin));
        if(noticia == 0) break;
        for(int i = 0; i < nRegistros; i++){
            for(int j = 0; j < registros[i]; j++){
                if(noticia == registro[i]->iDNoticia){
                    printNoticia(registro[i]);
                    break;
                }
            }
        }
    }

    // Ordenamos solo las filas de la matriz
    for(int i = 0; i < nRegistros; i++){
        sortd(registro[i], registros[i]);
    }

    printf("Noticias ordenadas: \n");
    for(int i = 0; i < nRegistros; i++){
        printf("Listado %d: \n", i+1);
        for(int j = 0; j < registros[i]; j++){
            printf("\tNoticia %d: \n", j+1);
            printNoticia(registro[j]);
        }
    }
}