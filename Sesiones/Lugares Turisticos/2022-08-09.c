#include <stdio.h>

#include "../libs/string/string.h"
#include "../libs/project/Zona/zona.h"
#include "../libs/LList/Llist.h"
#include "../libs/io/IO.h"

int main()
{
  // Creamos el listado de las zonas
  LList *zonas = new_llist();

  // Cargamos las zonas en memoria
  switch (loadZonas(zonas))
  {
  case -1:
    printf("Error al cargar las zonas\n");
    return -1;
    break;
  case 0:
    printf("Sin zonas por cargar\n");
    return 0;
    break;
  default:
    printf("Se han cargado %i zonas\n", llist_size(zonas));
    break;
  }

  imprimirZonas(zonas);
  int opcion = 0;
  while (1)
  {
    printf("Selecciona el ID de la zona a mostrar, -1 para reimprimir las zonas: \n $> ");
    if (evaluarInt(&opcion, stdin) == -1)
    {
      printf("Error al leer la opcion\n");
      return -1;
    }

    if (opcion == -1)
    {
      imprimirZonas(zonas);
    }
    else
    {
      if (opcion >= 0 && opcion < llist_size(zonas))
      {
        Zona *z = llist_get(zonas, opcion);
        printf("\tNombre: %s\n", z->nombre.str);
        printf("\tCosto: %i\n", z->costo);
      }
      else
      {
        printf("La opcion no es valida\n");
      }
    }
  }
}