#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct Stack_node{
    void *data;
    struct stack_node *next;
} Stack_node;

typedef struct Stack{
    int size;
    Stack_node* top;
} Stack;

void stack_push(Stack *stack, void *data);
void stack_pop(Stack *stack);
void* stack_top(Stack *stack);
int stack_size(Stack *stack);
void stack_destroy(Stack *stack);


#endif // STACK_H