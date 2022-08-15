#include "../sqs.h"

SQS sqs_create(int size){
    SQS sqs = (SQS)calloc(sizeof(struct SQS));
    sqs->bottom = 0;
    sqs->size = size;
    sqs->dataArray = (void **)calloc(sizeof(void *) * size);
    return sqs;
}

void sqs_destroy(SQS sqs){
    free(sqs->dataArray);
    free(sqs);
}

// Add data to the end of the queue
void sqs_enqueue(SQS sqs, void *data){
    // If the queue is full, return
    if(sqs->bottom == sqs->size){
        printf("Queue is full\n");
        return 0;
    }

    // Add data to the end of the queue
    sqs->dataArray[sqs->bottom] = data;
    sqs->bottom++;
}

// Remove data from the front of the queue
void* sqs_dequeue(SQS sqs){
    // If the queue is empty, return
    if(sqs->bottom == 0){
        printf("Queue is empty\n");
        return 0;
    }

    // Remove data from the front of the queue
    void *data = sqs->dataArray[0];
    sqs->dataArray[0] = 0;
    
    // Data alignment
    for(int i = 0; i < sqs->bottom; i++){
        sqs->dataArray[i] = sqs->dataArray[i + 1];
    }

    sqs->bottom--;
    return data;
}

// Add data to the end of the stack
void sqs_stack(SQS sqs, void *data){
    // Same as enqueue
    return sqs_enqueue(sqs, data);
}

// Remove data from the top of the stack
void* sqs_unstack(SQS sqs){
    // If the stack is empty, return
    if(sqs->bottom == 0){
        printf("Stack is empty\n");
        return 0;
    }

    // Remove data from the end of the stack
    void *data = sqs->dataArray[sqs->bottom-1];
    sqs->dataArray[sqs->bottom-1] = 0;
    sqs->bottom--;
    return data;
}