// Include header file
#include "sstring.h"
#include <stdlib.h>

String newString(){
    return 0;
}

String newStringFrom(String str){
    String s = malloc(strlen(str) + 1);
    strcpy(s, str);
    return s;
}

int setString(String str, String newStr){
    if (str == 0){
        return -1;
    }

    strcpy(str, newStr);
    return 1;
}