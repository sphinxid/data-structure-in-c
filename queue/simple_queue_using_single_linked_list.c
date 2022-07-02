#include <stdio.h>
#include <stdlib.h>

struct queue {
    int num;

    struct queue *next;
} *front, *rear;

void addToQueue(int num) {
    struct queue *newNode = (struct queue *) malloc(sizeof(struct queue));

    newNode->num = num;

    if ((front == NULL && (rear == NULL))) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = NULL;
    }

    return;
}

struct queue* getQueue() { 
    struct queue *ptrNode;
    struct queue *queueNode = (struct queue *) malloc(sizeof(struct queue));

    ptrNode = front;
    
    queueNode->num = ptrNode->num;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(ptrNode);

    return queueNode;
}

void printNode(struct queue *node) {
    printf("%d ", node->num);
}

void printAllNode() {

    struct queue *node;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    node = front;

    if (node) {
        while(node) {
            printNode(node);
            node = node->next;
        }
        printf("\n");
    }
    return;
}

int getQueueSize() {
    struct queue *node;
    int size = 0;

    node = front;
    if(node != NULL) {
        while(node) {
            node = node->next;
            size++;
        }
    }

    return size;
}

int main(void) {
    int arrayData[] = {67,8,31,55,70,3, 81, 47, 29, 62, 45};
    int i, arrayLen;
    struct queue *node;

    arrayLen = sizeof(arrayData)/sizeof(arrayData[0]);

    // insert data to queue
    for(i=0;i<arrayLen;i++) {
        addToQueue(arrayData[i]);
    }

    // print all queue data
    printf("Current queue data: \n");
    printAllNode();
    printf("\n");

    // consume the queue until queue data = 81
    i = 0;
    do {
        node = getQueue();
        i = node->num;
        printf("Currently consuming queue data = %d\n", i);
    } while(i != 81);

    // print all queue data
    printf("\n");
    printf("Current queue data: \n");
    printAllNode();

    // insert more data to queue
    for(i=0;i<arrayLen;i++) {
        addToQueue(arrayData[i]);
    }

    // print all queue data
    printf("\n");
    printf("Current queue data: \n");
    printAllNode();

    return 0;
}
