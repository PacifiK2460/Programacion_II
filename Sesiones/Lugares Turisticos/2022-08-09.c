#include <stdio.h>

#include "../libs/string/string.h"
#include "../libs/Zona/zona.h"
#include "../libs/graph/graph.h"


// TODO FIX W/ LIBS
// void loadZonas(struct Zona destination[], int total) {
//   for (int actual = 0; actual < total; actual++) {
//     destination[actual].nombre = ""; // TODO
//     destination[actual].costo = 0;   // TODO
//   }
// }

int main() {
  // Creamos el listado de las zonas
  Graph Lista = new_graph();

  // Cargamos las zonas en memoria
  if ( loadZonas(&Lista) == -1 ) {
    printf("Error al cargar las zonas\n");
    return -1;
  }

  // UNEXPECTED INPUT CHEKING LEFT IN TODO
  while (1) {
    printf("Selecciona el ID de la zona a mostrar: \n$");
    // int selected = 0;
    // scanf("%i", &selected);

    // if (selected > NZonas || selected < 1) {
    //   printf("Selecciona una zona registrada\n");
    //   continue;
    // }

    // printf("ZONA SELECCIONADA: %s, $%i\n", Listado[selected].nombre,
    //        Listado[selected].costo);
  }
}