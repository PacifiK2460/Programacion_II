#include "io/io.h"
#include "string/string.h"
#include <stdio.h>

typedef struct{
  int id;
  String string;
  //...
} test;

int main(){
  void* memory;
  
  int filas = 0;
  input("Filas: ", evaluarInt(&filas, stdin));

  memory = malloc(filas * sizeof(void*));
  for(int i = 0; i < filas; i++){
    memory[i] = malloc(sizeof(test));
    memory[i] -> id = i;
    setStringfromChar(memory[i] -> string, "LOREM IMPSUM");
  }
}