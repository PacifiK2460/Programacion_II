#include <stdio.h>

#include "../libs/string/string.h"
#include "../libs/Zona/zona.h"

// TODO FIX W/ LIBS
void loadZonas(struct Zona destination[], int total) {
  for (int actual = 0; actual < total; actual++) {
    destination[actual].nombre = ""; // TODO
    destination[actual].costo = 0;   // TODO
  }
}

int main() {
  // Cargamos las cantidad de zonas
  int NZonas = getZonas();
  if(NZonas == -1) {
    return -1;
  } else if (NZonas == 0) {
    printf("Sin zonas por motrar\n");
    return 0;
  }
  
  // Creamos el listado de las zonas
  struct Zona Listado[NZonas];
  // Cargamos las zonas en memoria
  loadZonas(Listado, NZonas);

  // UNEXPECTED INPUT CHEKING LEFT IN TODO
  while (1) {
    printf("Selecciona el ID de la zona a mostrar: \n$");
    int selected = 0;
    scanf("%i", &selected);

    if (selected > NZonas || selected < 1) {
      printf("Selecciona una zona registrada\n");
      continue;
    }

    printf("ZONA SELECCIONADA: %s, $%i\n", Listado[selected].nombre,
           Listado[selected].costo);
  }
}