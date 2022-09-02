// Static Queue Stack

#ifndef SQS_H
#define SQS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct SQS{
    int bottom;
    int size;
    void **dataArray;
} *SQS;

SQS sqs_create(int size);
void sqs_destroy(SQS sqs);

void sqs_enqueue(SQS sqs, void *data);
void *sqs_dequeue(SQS sqs);

void sqs_stack(SQS sqs, void *data);
void *sqs_unstack(SQS sqs);

#endif // SQS_H