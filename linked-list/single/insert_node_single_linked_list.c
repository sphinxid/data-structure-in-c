#include <stdio.h>
#include <stdlib.h>

// Linkedlist Seed Data: 99, 13, 43, 72, 68, 33, 92, 9, 30, 51, 2, 37, 82, 40, 17, 12, 47

/*
 *
 * Insert number 503 between 92 and 9 using insert new node in linked list.
 * (Using single linked list)
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

void pushAfterNode(struct data *node, int number) {
    curr = (struct data*) malloc(sizeof(struct data));

    curr->number = number;

    temp = node->next;
    node->next = curr;
    curr->next = temp;

    return;
}

struct data * findNode(int number) {
    curr = head;

    while(curr) {
        if(curr->number == number) {
            return curr;
        }

        curr = curr->next;
    }

    return NULL;
}

int main(void) {
    int seedData[] = {99, 13, 43, 72, 68, 33, 92, 9, 30, 51, 2, 37, 82, 40, 17, 12, 47};
    int i = 0;

    for(i=0;i<(sizeof(seedData)/sizeof(int));i++) {
        push(seedData[i]);
    }

    // see the current data
    view();

    // find node that has number value = 92
    curr = findNode(92);

    // check if it's the correct node
    printf("\nFound value = %d\n\n", curr->number);

    pushAfterNode(curr, 503);

    // see the current data
    view();

    return 0;
}
