// include guard
#ifndef ZONA_H
#define ZONA_H

#include <stdio.h>

#include "string/string.h"
#include "llist/llist.h"
#include "io/io.h"

typedef struct Zona{
  String nombre;
  int costo;
} Zona;

typedef struct Zonas {
  LList *root;
} *Zonas;

int cantidadZonas(Zonas zonas);
int loadZonas(Zonas Destination);
void imprimirZonas(Zonas zona);

Zona* getZona(Zonas zonas, int id);

#endif // ZONA_H