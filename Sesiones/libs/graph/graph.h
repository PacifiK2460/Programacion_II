#include <stdint.h>

typedef struct Leaf{
    void* data;
    /*   
        bnode stands for bidirectional node
        Cause we are using a graph, we need to have a way to go back and forth
        this is accomplished by having both pointers merged with a xor operation
    */
    Leaf *bnode;
} Leaf;

typedef struct Graph{
    Leaf *root;
    // TODO count graph floors
} Graph;