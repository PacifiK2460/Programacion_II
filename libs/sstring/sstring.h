// include guard
#ifndef STRING_H
#define STRING_H

#include <string.h>

// typedef struct String {
//     char *str;
//     int len;
// } String;

#define String char*

String newString();
String newStringFrom(String str);
int setString(String str, String newStr);
    
#endif // STRING_H