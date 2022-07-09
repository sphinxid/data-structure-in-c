#include <stdio.h>

// hashing by division method
// h(k) = k mod n
// Here, h(k) is the hash value obtained by dividing the key value k by size of hash table n using the remainder. It is best that n is a prime number as that makes sure the keys are distributed with more uniformity.

// An example of the Division Method is as follows:
// k=1276
// n=10
// h(1276) = 1276 mod 10
// = 6

int division_hash(int k, int n) {
    int res = 0;
    res = k % n;

    return res;
}

int main(void) {
    int k = 12345678; // key value
    int n = 15000; // hash table size

    printf("hash location = %d\n", division_hash(k, n));

    return 0;
}
