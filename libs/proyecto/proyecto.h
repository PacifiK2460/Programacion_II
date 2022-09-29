#ifndef PROYECTO_H
#define PROYECTO_H

// #ifndef AUTH_H
    // #include "auth.h"
// #endif
// 
// #ifndef ROUTES_H
    // #include "routes.h"
// #endif

enum ErrorType{
    UserERR = 0x100,
    RouteERR = 0x200,
    SystemERR = 0x300,
};

enum SystemErrors
{
    // OK = 0,
    MALLOC_FAULT = SystemERR,
    FILE_NOT_FOUND,
    FILE_PERMISSION_DENIED,
    FILE_OPEN_ERROR,
    FOPEN_FAULT
};

typedef struct Result{
    // If an error occurs, this will be set in the error field
    int Error_state;
    // if not, the pointer may be safe to use
    void* result;
} Result;

#endif