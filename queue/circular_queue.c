#include <stdio.h>
#include <stdlib.h>

struct queue {
    int *data;
    int maxSize;
    int head;
    int tail;
    int currentSize;
};

struct queue* newQueue(int queueSize) {

    struct queue *q = (struct queue*) malloc(sizeof(struct queue));

    q->data     = (int *) malloc(queueSize * sizeof(int));
    q->maxSize  = queueSize;
    q->head     = 0; // default value
    q->tail     = -1; // default value;
    q->currentSize = 0; // always zero on queue creation

    return q;
}

int addToQeue(struct queue *q, int num) {
    // check if queue > max queue size
    if (q->currentSize >= q->maxSize) {
        printf("Queue is Full!\n");
        return -1;
    }
    
    q->tail = (q->tail + 1) % q->maxSize;
    q->data[q->tail] = num;
    q->currentSize++;

    return 0;
}

int getQueue(struct queue *q) {
    int data;

    // check if queue is empty
    if (q->currentSize == 0) {
        return -1;
    }
    
    data = q->data[q->head];
    q->head = (q->head + 1) % q->maxSize;
    q->currentSize--;

    return data;
}

void printQueue(struct queue *q) {
    int i;

    if (q->currentSize > 0) {
        for(i=0;i<q->currentSize;i++) {
            printf("%d ", q->data[(q->head)+i]);
        }
    }
    else {
        printf("Queue is empty!");
    }
    printf("\n");

    return;
}

int main(void) {
    int arrayData[] = {7,19,72,44,62,10,9,34,50,27,83,4};
    int arrayLen, i, x;
    struct queue *q;

    // initilize new circular queue
    q = newQueue(15);

    // insert the seed data to queue
    arrayLen = sizeof(arrayData)/sizeof(arrayData[0]);
    for(i=0;i<arrayLen;i++) {
        addToQeue(q, arrayData[i]);
    }

    // print the current queue
    printf("Current Queue (%d): \n", q->currentSize);
    printQueue(q);

    // add '3' to the current queue
    addToQeue(q, 3);

    // print the current queue
    printf("Current Queue (%d): \n", q->currentSize);
    printQueue(q);

    x = q->currentSize;
    for(i=0;i<x;i++) {
        getQueue(q);
    }    

    // print the current queue
    printf("Current Queue (%d): \n", q->currentSize);
    printQueue(q);

    return 0;
}
