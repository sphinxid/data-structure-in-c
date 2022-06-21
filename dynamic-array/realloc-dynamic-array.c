#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // initilize static arrays
    int numbers[] = {34, 58, 12, 90, 13, 77, 45, 82, 2, 53};

    // initialize dynamic array with size 1
    int *store_numbers = (int*) malloc(1*sizeof(int));
    int i;

    for(i=0;i<sizeof(numbers)/sizeof(int);i++) {

        if(i > 0) {
            // resize the dynamic array +1 on while the for loop executed
            store_numbers = (int*) realloc(store_numbers, (1+i)*sizeof(int));
        }

        // storing numbers to the dynamic array
        store_numbers[i] = numbers[i];

        // print the data to stdout
        printf("%d\n", store_numbers[i]);
    }

    return 0;
}
