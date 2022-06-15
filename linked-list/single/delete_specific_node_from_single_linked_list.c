#include <stdio.h>
#include <stdlib.h>

// Linkedlist Seed Data: 12, 78, 53, 11, 72, 20, 99, 36, 13, 48, 23, 71, 15

/*
 * Delete specific node from linked list.
 * In the example, lets delete number 11.
 *
 */


struct data {
    int number;

    struct data *next;
} *head, *tail, *curr, *temp;

void view(void) {
    int i = 1;
    curr = head;

    printf("Data in LinkedList: \n");
    while(curr) {
        printf("[%d] = %d\n", i++, curr->number);
        curr = curr->next;
    }
}

void push(int number) {
    curr = (struct data*) malloc(sizeof(struct data));

    curr->number = number;

    if (head == NULL) {
        head = tail = curr;
    }
    else {
        tail->next = curr;
        tail = curr;
    }

    tail->next = NULL;
}

void findAndDeleteFromNode(int number) {

    curr = head;

    while(curr && curr->number != number) {
        temp = curr;
        curr = curr->next;
    }

    temp->next = curr->next;
    free(curr);

    return;
}

int main(void) {
    int seedData[] = {12, 78, 53, 11, 72, 20, 99, 36, 13, 48, 23, 71, 15};
    int i = 0;

    for(i=0;i<(sizeof(seedData)/sizeof(int));i++) {
        push(seedData[i]);
    }

    // see the current data
    view();

    findAndDeleteFromNode(11);

    // see the current data
    view();

    return 0;
}
