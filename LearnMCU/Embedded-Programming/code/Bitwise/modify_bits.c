#include <stdio.h>

/*1. Set or Clear a Specific Bit in a Register
    reg |= (1 << pos); → Set the bit by OR-ing with a mask.
    reg &= ~(1 << pos); → Clear the bit by AND-ing with the complement of a mask.
*/

unsigned char modifyBit(unsigned char reg, int pos, int mode) {
    if (mode == 1){ // set
        reg |= (1 << pos);
    }
    else { // clear 
        reg &= ~(1 << pos);
    }
    return reg;
}

int main() {
    unsigned char reg;
    int pos, mode;
    scanf("%hhu %d %d", &reg, &pos, &mode);
    printf("%d", modifyBit(reg, pos, mode));
    return 0;
}