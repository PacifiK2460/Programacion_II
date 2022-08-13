#include "../graph.h"

Graph new_graph(){
    Graph g = {.root = 0};
    return g;
}

void* graph_get_nth_leaf(Graph *graph, int n){
    Leaf *current = graph->root;
    Leaf *prev = 0;
    for(int i = 0; i < n; i++){
        // if current is null, we got an error
        if(current == 0) return 0;

        Leaf* next = (struct Leaf*)((uintptr_t)(current->bnode) ^ (uintptr_t)(prev));
        prev = current;
        current = next;
    }

    return current->data;
}

int graph_add_leaf(Graph *graph, void *data){
    Leaf *new = (Leaf*)malloc(sizeof(Leaf));
    if(new == 0) return -1;

    new->data = data;
    new->bnode = 0;
    
    if(graph->root == 0){
        graph->root = new;
        return 0;
    }
    
    Leaf *current = graph->root;
    Leaf *prev = 0;
    while(current != 0){
        Leaf* next = (struct Leaf*)((uintptr_t)(current->bnode) ^ (uintptr_t)(prev));
        prev = current;
        current = next;
    }

    prev->bnode = new;
    return 0;
}

void graph_free(Graph *graph){
    Leaf *current = graph->root;
    Leaf *prev = 0;
    while(current != 0){
        Leaf* next = (struct Leaf*)((uintptr_t)(current->bnode) ^ (uintptr_t)(prev));
        prev = current;
        current = next;
        free(prev);
    }
}
