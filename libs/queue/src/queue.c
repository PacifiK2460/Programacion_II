#include "../queue.h"

Queue Queue_new(){
    Queue queue;
    queue.size = 0;
    queue.head = 0;
    queue.tail = 0;
    return queue;
}

int Queue_enqueue(Queue *queue, void *data){
    Queue_node *node = (Queue_node*)malloc(sizeof(Queue_node));
    if(node == 0)
        return -1;
    node->data = data;
    node->next = 0;
    if (queue->size == 0){
        queue->head = node;
        queue->tail = node;
    }
    else{
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->size++;

    return 1;
}

void Queue_dequeue(Queue *queue){
    if (queue->size == 0)
        return;
    Queue_node *node = queue->head;
    queue->head = node->next;
    queue->size--;
    free(node);
}

void Queue_delete(Queue *queue){
    while (queue->size > 0)
        Queue_dequeue(queue);
}

void* Queue_peek(Queue *queue){
    if (queue->size == 0)
        return 0;
    return queue->head->data;
}

int Queue_size(Queue *queue){
    return queue->size;
}