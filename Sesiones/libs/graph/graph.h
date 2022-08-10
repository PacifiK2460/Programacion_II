struct leaf{
    void* data;
    /*   
        bnode stands for bidirectional node
        Cause we are using a graph, we need to have a way to go back and forth
        this is accomplished by having both pointers merged with a xor operation
    */
    leaf *bnode;
};

struct graph{
    leaf *root;
    // TODO count graph floors
};

graph new_graph(){
    graph g = {.root = 0};
    return g;
}

void* graph_get_nth_leaf(graph *g, int n){
    leaf *current = g->root;
    for(int i = 0; i < n; i++){
        current = current->bnode;
    }

    return current->data;
}