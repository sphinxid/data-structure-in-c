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

struct barang *findNode(int number) {

    curr = head;

    while(curr) {
        if(curr->number == number) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

void insertAfter(int number, int newNumber) {
    struct data *newNode = (struct data*) malloc(sizeof(struct data));
    struct data *temp1, *temp2;

    curr = findNode(number);

    if (curr) {
        newNode->number = newNumber;

        temp1 = curr;
        temp2 = curr->next;

        newNode->next = temp2;
        newNode->prev = curr;

        curr->next = newNode;
        curr->prev = temp1;
    }

    return;
}

int main(void) {
    int arr[] = {23, 45, 79, 3, 47, 11, 92, 60, 39, 28, 6, 72, 13, 28};
    int i;
    int newNumber = 1000;

    for(i=0;i<sizeof(arr)/sizeof(int);i++) {
        append(arr[i]);
    }

    printLL();
    insertAfter(3, newNumber);
    printLL();

    return 0;
}
