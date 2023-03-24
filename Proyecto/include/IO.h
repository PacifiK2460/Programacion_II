#pragma once

#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <stdbool.h>

#include "LIST.h"

DWORD WINAPI HandleInput();

typedef enum InputTypeName{
    SINGLE_WORD,
    LINE,
    SINGLE_CHAR,
    INTEGER,
    FLOATER,
    NONE
}InputTypeName;

typedef struct InputType{
    InputTypeName type;
    union InputBuffer{
        char* word;
        char* line;
        char character;
        int integer;
        float floating;
    };
} InputType;

typedef struct InputHandler
{
    InputType input;
    bool (*callback)(InputType);
} InputHandler, *PInputHandler;

typedef struct OutputSubsciption
{
    char* output;
    int with, height;
    void (*Render)(void* RenderArgs);
    void* RenderArgs;
} OutputSubsciption, *POutputSubsciption;

typedef struct OutputSubscribers
{
    char* output;
    List subscribers;
} OutputSubscribers, *POutputSubscribers;

POutputSubsciption subscribeOutput(POutputSubscribers outputSubscriber, void (*Render)(void* RenderArgs), void* RenderArgs);
