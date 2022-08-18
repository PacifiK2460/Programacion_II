#include "io/io.h"
#include "string/string.h"
#include "llist/llist.h"

#include <stdio.h>

int main(){
    int N;
    input("Ingrese el numero de Nombres: ", evaluarInt(&N, stdin));

    LList* StringList = LList_new();
    for(int i = 0; i < N; i++){
        int max;
        input("Ingrese el numero maximo de caracteres: ", evaluarInt(&max, stdin));
        String* string = newString();
        while(1){
          input("Ingrese el nombre: ", evaluarString(string, stdin));
          if(string.len < max)
            break;
        }

        LList_add(StringList, string);
    }

    for(int i = 0; i < N; i++){
        String* string = LList_get(StringList, i);
        printf("%s\n", string->str);
        freeString(string);
    }
    LList_free(StringList);
}