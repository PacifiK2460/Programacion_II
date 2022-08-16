#include "../zona.h"

int cantidadDeZonas() {
  FILE *archivo = fopen("zonas.cfg", "r+");
  if(archivo == NULL) {
    return -1;
  }

  char c = 0;
  int lineas = 0;
  while ((c = fgetc(archivo)) != EOF) {
    if (c == '\n')
      lineas++;
  }
  fclose(archivo);
  return lineas;
}

int loadZonas(LList* Destination){
  int j = (cantidadDeZonas()+1)/2;
  if(j <= 0) {
    return j;
  }

  FILE *archivo = fopen("zonas.cfg", "r+");
  if(archivo == NULL) {
    return -1;
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
    Zona* new = (Zona*)calloc(1,sizeof(Zona));
    if(new == 0){
      fclose(archivo);
      return -1;
    }
    setStringFromString(&new->nombre, nameBuffer);
    new->costo = costBuffer;

    // we add the new leaf to the graph
    if(LList_add(Destination, new) == -1){
      fclose(archivo);
      return -1;
    }

  }
  
  fclose(archivo);
  return 1;
}

int cantidadZonas(LList* zonas){
  return LList_size(zonas);
}

void imprimirZonas(LList* zona){
  int j = LList_size(zona);
  for(int i = 0; i < j; i++){
    Zona* z = LList_get(zona, i);
    printf("[Zona %i]: %s, $%i\n",i, z->nombre.str, z->costo);
  }
}

Zona* getZona(LList* zonas, int id){
  return LList_get(zonas, id);
}