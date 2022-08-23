#include "io/io.h"
#include "string/string.h"
#include "llist/llist.h"
#include <stdio.h>
#include <stdlib.h>

#define CALIFICACIONES 3

typedef struct Dato{
  int matricula;
  String nombre;
  int edad;
  String carrera;
  double calificaciones[CALIFICACIONES];
} Dato;

int writeDato(Dato dato, FILE* stream){
  if(stream == 0) return -1;

  fprintf(stream,"%i\n"
  "%s\n"
  "%i\n"
  "%s\n"
  "%lf\n"
  "%lf\n"
  "%lf\n",
  dato.matricula,
  dato.nombre.str,
  dato.edad,
  dato.carrera.str,
  dato.calificaciones[0],
  dato.calificaciones[1],
  dato.calificaciones[2]);

  return 1;
}

int main(){
  LList* memory = LList_new();
  
  int filas = 0;
  input("Filas: ", evaluarInt(&filas, stdin));

  for(int item = 0; item < filas; item++){
    Dato* data = malloc(sizeof(Dato));
    if(data == 0) return -1;

    input("Matricula: ", evaluarInt(&data->matricula, stdin));
    input("Nombre: ", evaluarString(&data->nombre, stdin));
    input("Edad: ", evaluarInt(&data->edad, stdin));
    input("Carrera: ", evaluarString(&data->carrera, stdin));

    for(int cal = 0; cal < CALIFICACIONES; cal++){
      printf("Calificación %i: ", cal);
      input("", evaluarDouble(&data->calificaciones[cal], stdin));
    }

    LList_add(memory, data);
  }


  printf("Datos obtenidos: \n");

  for(int item = 0; item < filas; item++){
    Dato* current = LList_get(memory, item);

    printf("ITEM %i\n"
          "\tMatricula: %i\n"
          "\tNombre: %s\n"
          "\tEdad: %i\n"
          "\tCarrera: %s\n",
          item, current->matricula,
          current->nombre.str,
          current->edad, current->carrera.str);
    
    for(int i = 0; i < CALIFICACIONES; i++){
      printf("\tCalificación %i: %lf\n", i, current->calificaciones[i]);
    }

    FILE* stream = fopen("data.txt", "a+");
    if(stream == 0) return -1;
    writeDato(*current, stream);
    fclose(stream);

    printf("\n");

    freeString(&current->nombre);
    freeString(&current->carrera);
    free(current);
  }
  LList_free(memory);

  return 0;
}