#include "../stack.h"


void stack_push(Stack *stack, void *data)
{
    Stack_node *node = (Stack_node*)malloc(sizeof(Stack_node));
    if(node == 0) {
        return;
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
} 

void stack_pop(Stack *stack)
{
    if (stack->size == 0)
        return;
    Stack_node *node = stack->top;
    stack->top = node->next;
    stack->size--;
    free(node);
}

void* stack_top(Stack *stack)
{
    if (stack->size == 0)
        return 0;
    return stack->top->data;
}

int stack_size(Stack *stack)
{
    return stack->size;
}

void stack_destroy(Stack *stack)
{
    while (stack->size > 0)
        stack_pop(stack);
}