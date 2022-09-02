#include "../zona.h"

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

int loadZonas(Graph* Destination){
  for(int i = 0, j = getZonas(); i < j; i++){
    // we go line by line, reading the name and the cost
    // TODO fix this, add support for the string itself to read from file
    char name[50];
    int costo;
    
    FILE *archivo = fopen("zonas.cfg", "r");
    if(archivo == NULL) {
      return -1;
    }
    
    fscanf(archivo, "%s %i", name, &costo);
    fclose(archivo);

    String nombre = newFrom(name);

    // we create a new node with the name and the cost
    Zona* new = 

    // we add the new leaf to the graph
    graph_add_leaf(Destination, (void*)nombre);
  }
}