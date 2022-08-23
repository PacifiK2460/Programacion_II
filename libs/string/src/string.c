// Include header file
#include "../string.h"

String *newString(){
    String* s = malloc(sizeof(String));
    s->str = 0;
    s->len = 0; 
    return s;
}

String *newFrom(char *str){
    String* s = malloc(sizeof(String));
    s->len = strlen(str);
    s->str = malloc((s->len + 1) * sizeof(char));
    strcpy(s->str, str);
    s->str[s->len] = '\0';
    return s;
}

int setStringFromChar(String* dest,char* src){
    if(dest->str != 0){
        free(dest->str);
    }

    dest->len = strlen(src);
    dest->str = malloc(dest->len * sizeof(char));

    if(dest->str == 0){
        return -1;
    }

    strcpy(dest->str, src);
    dest->str[dest->len] = '\0';
    return 1;
}

int setStringFromString(String* Dest, String* Src){
    if(Dest->str != 0){
        free(Dest->str);
    }

    Dest->len = Src->len;
    Dest->str = malloc(Dest->len * sizeof(char));

    if(Dest->str == 0){
        return -1;
    }

    strcpy(Dest->str, Src->str);
    Dest->str[Dest->len] = '\0';
    return 1;
}


void freeString(String* s){
    free(s->str);
}