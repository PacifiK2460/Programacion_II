// Include header file
#include "../string.h"

String new(){
    String s = {.str = 0, .len = 0};
    return s;
}

String newFrom(char *str){
    String s = new();
    s.str = str;
    s.len = strlen(str);
    return s;
}

int setStringFromChar(String* dest,char* src){
    if(dest->str != 0){
        free(dest->str);
    }

    dest->len = strlen(src);
    dest->str = malloc(dest->len * sizeof(char));

    if(dest->str == 0)
        return -1;

    strcpy(dest->str, src);
    dest->str[dest->len] = '\0';
}

int setStringFromString(String* Dest, String* Src){
    if(Dest->str != 0){
        free(Dest->str);
    }

    Dest->len = Src->len;
    Dest->str = malloc(Dest->len * sizeof(char));
    strcpy(Dest->str, Src);
    Dest->str[Dest->len] = '\0';
}


void freeString(String* s){
    free(s->str);
}