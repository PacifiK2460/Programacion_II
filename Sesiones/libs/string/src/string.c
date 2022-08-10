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

void freeString(String s){
    free(s.str);
}