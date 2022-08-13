#include "../zona.h"

int cantidadDeZonas() {
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

int loadZonas(Zonas Destination){
  FILE *archivo = fopen("zonas.cfg", "r");
  if(archivo == NULL) {
    return -1;
  }

  int j = cantidadDeZonas();
  if(j <= 0) {
    return j;
  }


  for(int i = 0;i < j; i++){
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
    if(llist_add(Destination->root, new) == -1){
      fclose(archivo);
      return -1;
    }
  }
  
  fclose(archivo);
  return 1;
}

int cantidadZonas(Zonas zonas){
  return llist_size(zonas->root);
}

void imprimirZonas(Zonas zona){
  for(int i = 0, j = llist_size(zona); i < j; i++){
    Zona* z = llist_get(zona, i);
    printf("[Zona]: %s, $%i\n", z->nombre, z->costo);
  }
}

Zona* getZona(Zonas zonas, int id){
  return llist_get(zonas->root, id);
}