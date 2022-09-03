#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../libs/io/io.h"
#include "../../libs/string/string.h"

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
    String* noticia;
    String* encabezado;
    String* nombreAutor;
} Noticia;

int main(){
    srand(time(0));

    // Tabla dinamica de noticias
    Noticia** tablaNoticias;

    int filas;
    input("Introduce el numero de filas: ", evaluarInt(&filas, stdin));
    int columnas[filas];

    tablaNoticias = (Noticia**) malloc(filas * sizeof(Noticia*));
    for(int i = 0; i < filas; i++){
        input("Introduce el numero de noticias: ", evaluarInt(&columnas[i], stdin));
        tablaNoticias[i] = (Noticia*) malloc(sizeof(Noticia));

        for(int j = 0; j < columnas[i]; j++){
            tablaNoticias[i][j].iDNoticia = rand() % 100;
            tablaNoticias[i][j].clasificacion = rand() % 5 + 1;
            tablaNoticias[i][j].tipo = rand() % 2 + 1;
            tablaNoticias[i][j].noticia = newString("Noticia");
            tablaNoticias[i][j].encabezado = newString("Encabezado");
            tablaNoticias[i][j].nombreAutor = newString("Nombre del autor");
        }
    }

    // Imprimir tabla
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas[i]; j++){
    }
}