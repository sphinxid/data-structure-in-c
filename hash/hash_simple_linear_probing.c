#include <stdio.h>

// buat program dengan bahasa c untuk input data bilangan satu sampai seratus lima puluh dengan menggunakan konsep liner probing. perhatikan untuk input data yang dobel

#define HASH_SIZE 200
int table[HASH_SIZE] = {NULL};
int count = 0;

int calc_hash(int k) {
    return k % HASH_SIZE;
}

void insert(int k) {
    int rs = 0;
    rs = calc_hash(k);

    if (count == HASH_SIZE) {
        printf("Hash table is FULL!\n");
        return;
    }

    if (table[rs] == NULL) {
        table[rs] = k;
    }
    else {
        while(table[rs] != NULL) {
            rs = (rs+1) % HASH_SIZE;
            if (table[rs] == NULL) {
                table[rs] = k;
                break;
            }
        }
    }

    count++;

    return;
}

int print_hash() {
    int i = 0;
    int len = 0;

    len = sizeof(table)/sizeof(table[0]);
    for(i=0;i<len;i++) {
        printf("(hash) %d = (val) %d\n", i, table[i]);
    }
}

int main(void) {
    int i = 0;
    int max = 151;

    for(i=1;i<max;i++) {
        insert(i);
    }
    for(i=1;i<max;i++) {
        insert(i);
    }

    print_hash();

    return 0;
}
