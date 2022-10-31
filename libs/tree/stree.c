#include "stree.h"

int tree_insert(Tree *tree, void* data, int (*compare)(void*, void*)){
    if(data == NULL || compare == NULL){
        return -1;
    }

    if(tree->root == NULL){
        tree->root = (Node*)calloc(1,sizeof(Node));
        if(tree->root == NULL){
            return -1;
        }
        tree->root->data = data;
        tree->root->minor = NULL;
        tree->root->major = NULL;
        tree->size++;
        return 1;
    }

    Node *current = tree->root;
    while(1){
        if(compare(data, current->data) < 0){
            if(current->left == NULL){
                current->left = (Node*)calloc(1,sizeof(Node));
                if(current->left == NULL){
                    return -1;
                }
                current->left->data = data;
                current->left->left = NULL;
                current->left->right = NULL;
                tree->size++;
                return 1;
            }
            current = current->left;
        }else if(compare(data, current->data) > 0){
            if(current->right == NULL){
                current->right = (Node*)calloc(1,sizeof(Node));
                current->right->data = data;
                current->right->left = NULL;
                current->right->right = NULL;
                tree->size++;
                return 1;
            }
            current = current->right;
        }
        else{
            return -2;
        }
    }
    return 1;
}

int tree_get_index(Tree *tree, int index, int (*compare)(void*, void*)){
    if(tree->root == NULL){
        return -1;
    }

    if(index < 0 || index >= tree->size){
        return -2;
    }

    if(compare == NULL){
        return -3;
    }

    
}

