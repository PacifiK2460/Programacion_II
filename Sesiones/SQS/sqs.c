#include <stdio.h>
#include "sqs/sqs.h"

int main(){
    SQS sqs = sqs_create(10);

    for(int i = 0; i < 5; i++){
        printf("+[%d] %d\n",i, i);
        sqs_enqueue(sqs, (void *)i);
    }

    for(int i = 0; i < 2; i++){
        printf("-[%d] %d\n",i, (int)sqs_unstack(sqs));
    }

    for(int i = 0; i < 2; i++){
        printf("-[%d] %d\n",i, (int)sqs_dequeue(sqs));
    }

    for(int i = 0; i < 10; i++){
        printf("+[%d] %d\n",i, sqs_dequeue(sqs));
    }

    sqs_destroy(sqs);
}