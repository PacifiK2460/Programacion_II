#include "string.h"

String* newString(const wchar_t* str){
    size_t len = wcslen(str);
    String* newStr = calloc(len ,sizeof(String));
    newStr->len = len;
    newStr->str = calloc(len ,sizeof(wchar_t));
    wcscpy(newStr->str, str);
    return newStr;
}

void freeString(String* str){
    if(str == NULL)
        return;

    if(str->str != NULL)
        free(str->str);
        
    free(str);
}