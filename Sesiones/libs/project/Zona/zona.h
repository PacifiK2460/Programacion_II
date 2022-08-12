// include guard
#ifndef ZONA_H
#define ZONA_H

#include <stdio.h>

#include "../string/string.h"
#include "../LList/Llist.h"
#include "../io/IO.h"

typedef struct Zona {
  String nombre;
  int costo;
} Zona;

int loadZonas(LList* Destination);
void imprimirZonas(LList* zona);

#endif // ZONA_H