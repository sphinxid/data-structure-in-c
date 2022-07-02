#include <stdio.h>
#include <stdlib.h>

struct stack {
    int num;

    struct stack *next;
} *front, *tail;

void push(int num) {
    struct stack *node = (struct stack*) malloc(sizeof(struct stack));

    node->num = num;

    if (front == NULL) {
        front = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
        tail->next = NULL;
    }

    return;
}

int pop() {
    struct stack *node = NULL;
    struct stack *prev = NULL;
    int num = -1;

    node = front;

    if(node) {
        while(node->next) {
            prev = node;
            node = node->next;
        }

        num = node->num;

        if(node == front) {    
            tail = front = NULL;
        }
        else {
            tail = prev;
            prev->next = NULL;
        }

        free(node);
    }

    return num;
}

void printStack() {
    struct stack *node;

    node = front;
    if(node) {
        while(node) {
            printf("%d ", node->num);
            node = node->next;
        }
    }
    else {
        printf("Stack is empty!\n");
    }
    printf("\n");

    return;
}

int getStackSize() {
    struct stack *node;
    int size = 0;

    node = front;
    if(node) {
        size++;
        node = node->next;
    }

    return size;
}

int main(void) {
    int dataNumbers[] = {60, 13, 83, 4, 21, 72, 11, 43, 99, 27, 54, 85};
    int i, arrayLen, num;

    arrayLen = sizeof(dataNumbers)/sizeof(dataNumbers[0]);

    // print current stacks
    printStack();
    printf("\n");

    // insert data to stack
    for(i=0;i<arrayLen;i++) {
        push(dataNumbers[i]);
    }

    // print current stacks
    printStack();
    printf("\n");

    for(i=0;i<arrayLen;i++) {
        num = pop();
        printf("num popped = %d\n", num);
        printStack();
        printf("\n");        
    }

    return 0;
}
