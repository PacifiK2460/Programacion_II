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

int cantidadZonas(LList* zonas);
int loadZonas(LList* Destination);
void imprimirZonas(LList* zona);

Zona* getZona(LList* zonas, int id);

#endif // ZONA_H