// include guard
#ifndef STRING_H
#define STRING_H

typedef struct String {
    char *str;
    int len;
} String;

String new();
String newFrom(char *str);
void freeString(String s);

#endif // STRING_H