#include "../../libs/io/io.h"
#include "llist/llist.h"

#include <stdio.h>

int main(){
    int N;
    input("Ingrese el numero de Nombres: ", evaluarInt(&N, stdin));

    LList* StringList = LList_new();
    for(int i = 0; i < N; i++){
        char nombre[100];
        input("Ingrese el nombre: ", evaluarString(nombre, stdin));
        String* string = String_new();
        setStringFromChar(string, nombre);


        LList_add(StringList, string);
    }

    for(int i = 0; i < N; i++){
        String* string = LList_get(StringList, i);
        printf("%s", string->str);
        freeString(string);
    }
    LList_free(StringList);
}