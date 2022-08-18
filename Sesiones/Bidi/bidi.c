#include "io/io.h"
#include "string/string.h"
#include "llist/llist.h"

#include <stdio.h>

int main(){
    int N;
    input("Ingrese el numero de Nombres: ", evaluarInt(&N, stdin));

    LList* StringList = LList_new();
    for(int i = 0; i < N; i++){
        String* string = newString();
        input("Ingrese el nombre: ", evaluarString(string, stdin));

        LList_add(StringList, string);
    }

    for(int i = 0; i < N; i++){
        String* string = LList_get(StringList, i);
        printf("%s\n", string->str);
        freeString(string);
    }
    LList_free(StringList);
}