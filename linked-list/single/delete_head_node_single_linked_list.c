#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linkedlist Seed Data: 90, 12, 37, 81, 20, 45, 71, 3, 66, 103, 29, 47, 8, 10, 92, 41

/*
 *
 * Delete the head node from single linked list.
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

int deleteNodeFirst() {

    if(head == NULL) {
        // there is no data
        return -1;
    }

    curr = head;
    head = head->next;

    free(curr);

    return 1;
}


int main(void) {
    int seedData[] = {90, 12, 37, 81, 20, 45, 71, 3, 66, 103, 29, 47, 8, 10, 92, 41};
    int i = 0;

    for(i=0;i<(sizeof(seedData)/sizeof(int));i++) {
        push(seedData[i]);
    }

    // see the current data
    view();

    // try to delete the first node (head)
    deleteNodeFirst();

    // see the current data
    view();

    return 0;
}
