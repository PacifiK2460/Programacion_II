#pragma once

#include <stdlib.h>
#include <stdio.h>

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
extern void* pop(Tree *tree);

extern void* tree_search(Tree *tree, void* data, int (*compare)(void*, void*));

extern void tree_print(Tree *tree, void (*print)(void *));