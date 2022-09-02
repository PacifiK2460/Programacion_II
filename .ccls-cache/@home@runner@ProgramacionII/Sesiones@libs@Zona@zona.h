// include guard
#ifndef ZONA_H
#define ZONA_H

#include <stdio.h>

#include "../string/string.h"
#include "../graph/graph.h"

typedef struct Zona {
  String nombre;
  int costo;
} Zona;

int loadZonas(Graph* Destination);

#endif // ZONA_H