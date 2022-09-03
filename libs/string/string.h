// include guard
#ifndef STRING_H
#define STRING_H

typedef struct String {
    char *str;
    int len;
} String;

String *newString();
String *newFrom(char *str);
int setStringFromChar(String* dest,char* src);
int setStringFromString(String* Dest, String* Src);
void freeString(String* s);
    
#endif // STRING_H