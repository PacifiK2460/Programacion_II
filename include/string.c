#include "string.h"

int newStringFrom(const char* src, String* dest){
    if(src == NULL)
        return -1;

    dest->len = strlen(src);

    if(dest->str != NULL)
        free(dest->str);

    dest->str = calloc(dest->len + 1, sizeof(char));
    if(dest->str == NULL)
        return -1;

    strcpy(dest->str, src);
    
    // Null terminate it
    dest->str[dest->len] = '\0';
    return 0;
}

void freeString(String* str){
    if(str == NULL)
        return;

    if(str->str != NULL)
        free(str->str);
        
    free(str);
}