// include guard
#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
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

Graph new_graph();
void* graph_get_nth_leaf(Graph *graph, int n);
int graph_add_leaf(Graph *graph, void *data);
void graph_free(Graph *graph);

#endif // GRAPH_H