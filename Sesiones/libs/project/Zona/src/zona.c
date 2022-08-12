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

int loadZonas(LList* Destination){
  FILE *archivo = fopen("zonas.cfg", "r");
  if(archivo == NULL) {
    return -1;
  }

  for(int i = 0, j = getZonas(); i < j; i++){
    // we go line by line, reading the name and the cost
    String* nameBuffer = new_string();
    if(nameBuffer == 0){
      close(archivo);
      return -1;
    }
    int costBuffer = 0;

    if(evaluarString(nameBuffer, archivo) == -1){
      fclose(archivo);
      return -1;
    }
    if(evaluarInt(&costBuffer, archivo) == -1){
      fclose(archivo);
      return -1;
    }
    
    // we create a new node with the name and the cost
    Zona* new = malloc(sizeof(Zona));
    if(new == 0){
      fclose(archivo);
      return -1;
    }
    setStringFromString(&new->nombre, nameBuffer);
    new->costo = costBuffer;

    // we add the new leaf to the graph
    graph_add_leaf(Destination, new);
  }
  
  fclose(archivo);
}

void imprimirZonas(LList* zona){
  for(int i = 0, j = llist_size(zona); i < j; i++){
    Zona* z = llist_get(zona, i);
    printf("[Zona]: %s, $%i\n", z->nombre, z->costo);
  }
}