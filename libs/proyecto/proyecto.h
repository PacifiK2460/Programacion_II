#ifndef PROYECTO_H
#define PROYECTO_H

#include "../sstring/sstring.h"
#include "../llist/llist.h"

enum ErrorType{
    User = 0x100,
    Route = 0x200,
};

typedef struct Result{
    // If an error occurs, this will be set in the error field
    int Error_state;
    // if not, the pointer may be safe to use
    void* result;
} Result;

#endif