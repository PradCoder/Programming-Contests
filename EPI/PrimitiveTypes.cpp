#include "bits/stdc++.h"
#define MASK_SIZE 16
#define BIT_MASK 0xFFFF

vector<int> precomputedReverse, precomputedParity;
short countBits(int x){
    short numBits = 0;
    while(x != 0){
        numBits != (x & 1);
        x >>= 1;
    }
    return numBits;
}

//short parity(long x){
//    short result = 0;
//    while (x != 0){
//        result ^= (x & 1);
//        x >>= 1;
//    }
//    return result;
//}

//MORE EFFICIENT PARITY
short parity(long x){
    short result = 0;
    while(x != 0){
        result ^= 1;
        x &= (x - 1);   // Drops the lowest set bit of x
    }
    return result;
}

//Using precomputations
//short parity(long x) {
//    return (short) (precomputedParity [(int) ((x >> (3 * MASK_SIZE)) & BIT_MASK)] ^
//                    precomputedParity [(int) ((x >> (2 * MASK_SIZE)) & BIT_MASK)] ^
//                    precomputedParity [(int) ((x >> MASK_SIZE) & BIT_MASK)] ^
//                    precomputedParity [(int) (x & BIT_MASK)]);
//}

//x&(x-1) equal x with the lowest set bit erased
//short parity(long x){
//    x ^= x >> 32;
//    x ^= x >> 16;
//    x ^= x >> 8;
//    x ^= x >> 4;
//    x ^= x >> 2;
//    x ^= x >> 1;
//    return (short) (x & 0x1);
//}

long swapBits(long x, int i, int j){
    // Extract the i-th and j-th bits, and see if they differ.
    if (((x >> i) & 1) != ((x >> j) & 1)){
        // i-th and j-th bits differ. We will swap them by flipping their values.
        // Select the bits to flip with bitMask. Since x^1 = 0 when x = 1 and 1
        // when x = 0, we can perform the flip XOR.
        long bitMask = (1L << i) | (1L << j);
        x ^= bitMask;
    }

    return x;
}

long reverseBits(long x){
    return precomputedReverse[(int)(x & BIT_MASK)] << (3 * MASK_SIZE) |
           precomputedReverse[(int)((x >> MASK_SIZE) & BIT_MASK)] << (2* MASK_SIZE) |
           precomputedReverse[(int)((x >> (2 * MASK_SIZE)) & BIT_MASK)] << MASK_SIZE |
           precomputedReverse[(int)((x >> (3 * MASK_SIZE)) & BIT_MASK)];
}
