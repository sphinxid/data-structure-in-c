#include <stdio.h>
#include <stdlib.h>

#define CHAIN_SIZE 5

struct node {
    int num;
    struct node *next;
};

struct node *chain[CHAIN_SIZE];

void init_chain() {
    int i = 0;

    for(i=0;i<CHAIN_SIZE;i++) {
        chain[i] = NULL;
    }
}

void insert(int v) {
    int k;
    struct node *n = (struct node*) malloc(sizeof(struct node));

    n->num = v;
    n->next = NULL;

    // calculate hash using division method
    k = v % CHAIN_SIZE;

    // check if chain[k] is NULL
    if (chain[k] == NULL) {
        chain[k] = n;
    }
    // if collision
    else {
        struct node *t = chain[k];

        // go to end of a node
        while(t->next) {
            t = t->next;
        }

        t->next = n;
    }

    return;
}

void print_all() {
    int i;

    for(i=0;i<CHAIN_SIZE;i++) {
        struct node *t = chain[i];

        printf("chain[%d]-->", i);
        while(t) {
            printf("%d -->", t->num);
            t = t->next;
        }
        printf("NULL\n");
    }

    return;
}

int main(void) {
    int min = 0;
    int max = 250;
    
    for(min;min<=max;min++) {
        insert(min);
    }

    print_all();

    return 0;
}
