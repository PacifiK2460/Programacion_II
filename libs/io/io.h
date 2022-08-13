#ifndef SMARTIO_H
#define SMARTIO_H

#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../string/string.h"

// We evaluar an input from the desired stream
int evaluarInt(int* dest, FILE* stream);
int evaluarDouble(double* dest, FILE* stream);
int evaluarString(String* dest, FILE* stream);
int evaluarChar(char* Dest, FILE* stream);

#define input(str, condition)    \
    while (1)              \
    {                      \
        printf("%s", str); \
        if (condition) break;   \
    }


#endif // SMARTIO_H