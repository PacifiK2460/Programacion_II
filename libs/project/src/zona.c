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
    String* nameBuffer = newString();
    if(nameBuffer == 0){
      fclose(archivo);
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
    if(LList_add(Destination->root, new) == -1){
      fclose(archivo);
      return -1;
    }
  }
  
  fclose(archivo);
  return 1;
}

int cantidadZonas(Zonas zonas){
  return LList_size(zonas->root);
}

void imprimirZonas(Zonas zona){
  int j = LList_size(zona->root);
  for(int i = 0; i < j; i++){
    Zona* z = LList_get(zona->root, i);
    printf("[Zona]: %s, $%i\n", z->nombre.str, z->costo);
  }
}

Zona* getZona(Zonas zonas, int id){
  return LList_get(zonas->root, id);
}