#ifndef BIDI_H
#define BIDI_H

#include <stdlib.h>

typedef struct bidi{
    int* arr;
    int COLS;
    int ROWS;
} bidi;

void newBidi(bidi* arr, int COLS, int ROWS);

void freeBidi(bidi* arr);

void printBidi(bidi* arr);

void fillBidi(bidi* arr);

#endif // BIDI_H