#include <stdio.h>

int getZonas() {
  FILE *archivo = fopen("zonas.cfg", "r");
  if(archivo == NULL) {
    return -1;
  }
  char c = 0;
  int lineas = 0;
  while ((c = fgetc(archivo++)) != EOF) {
    if (c == '\n')
      lineas++;
  }
  fclose(archivo);
  return lineas;
}