#include "stree.h"

int tree_insert(Tree *tree, void *data, int (*compare)(void *, void *))
{
    if (data == NULL || compare == NULL)
    {
        return -1;
    }

    if (tree->root == NULL)
    {
        tree->root = (sorted_tree_node *)calloc(1, sizeof(sorted_tree_node));
        if (tree->root == NULL)
        {
            return -1;
        }
        tree->root->data = data;
        tree->root->minor = NULL;
        tree->root->major = NULL;
        tree->size++;
        return 1;
    }

    sorted_tree_node *current = tree->root;
    while (1)
    {
        if (compare(data, current->data) < 0)
        {
            if (current->minor == NULL)
            {
                current->minor = (sorted_tree_node *)calloc(1, sizeof(sorted_tree_node));
                if (current->minor == NULL)
                {
                    return -1;
                }
                current->minor->data = data;
                current->minor->minor = NULL;
                current->minor->major = NULL;
                tree->size++;
                return 1;
            }
            current = current->minor;
        }
        else if (compare(data, current->data) > 0)
        {
            if (current->major == NULL)
            {
                current->major = (sorted_tree_node *)calloc(1, sizeof(sorted_tree_node));
                current->major->data = data;
                current->major->minor = NULL;
                current->major->major = NULL;
                tree->size++;
                return 1;
            }
            current = current->major;
        }
        else
        {
            return -2;
        }
    }
    return 1;
}

void *_pop(sorted_tree_node *node)
{
    if (node == NULL)
        return NULL;

    if (node->minor == NULL && node->major == NULL)
    {
        void *data = node->data;
        // free(node);
        return data;
    }

    if (node->minor == NULL)
    {
        sorted_tree_node *major = node->major;

        void *data = node->data;

        free(node);

        node = major;

        return data;
    }

    _pop(node->minor);
}

extern void *pop(Tree *tree)
{
    if (tree->root == NULL)
    {
        return NULL;
    }

    return _pop(tree->root);
}

extern void *tree_search(Tree *tree, void *data, int (*compare)(void *, void *))
{
    if (tree->root == NULL)
        return NULL;

    sorted_tree_node *current = tree->root;
    while (1)
    {
        if (compare(data, current->data) < 0)
        {
            if (current->minor == NULL)
                return NULL;
            current = current->minor;
        }
        else if (compare(data, current->data) > 0)
        {
            if (current->major == NULL)
                return NULL;
            current = current->major;
        }
        else
        {
            return current->data;
        }
    }
}

void _print(sorted_tree_node *node, void (*print)(void *))
{
    if (node->minor == NULL && node->major == NULL)
    { 
        print(node->data);
    }
    if (node->minor != NULL)
        _print(node->minor, print);

    if (node->major != NULL)
        _print(node->major, print);
}
void tree_print(Tree *tree, void (*print)(void *))
{
    if (tree->root == NULL)
    {
        return;
    }

    sorted_tree_node *current = tree->root;
    if (current->minor != NULL)
    {
        _print(current->minor, print);
    }

    if (current->major != NULL)
    {
        _print(current->major, print);
    }
}