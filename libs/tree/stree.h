#pragma once

#include <stdlib.h>

typedef struct _sorted_tree_node {
    void* data;
    struct _sorted_tree_node *minor;
    struct _sorted_tree_node *major;
} sorted_tree_node;

typedef struct _sorted_tree {
    sorted_tree_node *root;
    int size;
} Tree;

extern int tree_insert(Tree *tree, void* data, int (*compare)(void*, void*));
extern int tree_get(Tree *tree, void* data, int (*compare)(void*, void*));
extern int tree_get_index(Tree *tree, int index, int (*compare)(void*, void*));