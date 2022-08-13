#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct Queue_node {
    void *data;
    struct Queue_node *next;
} Queue_node;

typedef struct Queue {
    Queue_node *head;
    Queue_node *tail;
    int size;
} Queue;

Queue Queue_new();
int Queue_enqueue(Queue *queue, void *data);
void Queue_dequeue(Queue *queue);
void Queue_delete(Queue *queue);
void* Queue_peek(Queue *queue);
int Queue_size(Queue *queue);

#endif // QUEUE_H