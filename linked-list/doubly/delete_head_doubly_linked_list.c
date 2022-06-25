#include <stdio.h>
#include <stdlib.h>

struct data {
    int number;

    struct data *next, *prev;
} *head, *tail, *curr;

void append(int n) {
    struct data *node = (struct data*) malloc(sizeof(struct data));

    node->number = n;

    if (head == NULL) {
        head = tail = node;
    }
    else {
        tail->next = node;
        node->prev = tail;

        tail = node;

    }

    head->prev = NULL;
    tail->next = NULL;

    return;
}

void deleteHead() {
    if (head != NULL) {
        curr = head;
        
        head = curr->next;
        head->prev = NULL;

        free(curr);
    }
}

void printLL(){
    curr = head;

    printf("List Data inside LinkedList: \n");
    while(curr) {
        printf("%d ", curr->number);
        curr = curr->next;
    }
    printf("\n");

    return;
}

int main(void) {
    int arr[] = {23, 45, 79, 3, 47, 11, 92, 60, 39, 28, 6, 72, 13, 28};
    int i;

    for(i=0;i<sizeof(arr)/sizeof(int);i++) {
        append(arr[i]);
    }

    printLL();
    deleteHead();
    printLL();

    return 0;
}
