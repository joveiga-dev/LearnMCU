/*
Extract a nibble (4-bit value) from an 8-bit register.

    The user provides an 8-bit integer (register value) and a nibble position
     (0 for lower nibble, 1 for upper nibble).value.
*/

#include <stdio.h>

unsigned char extract_nibbles(unsigned char reg, int pos) {
    if(pos == 0) {
        return reg & 0x0F;
    }
    else {
        return (reg >> 4) & 0x0F;
    }
}

int main() {
    unsigned char reg;
    int pos;
    scanf("%hhu %d", &reg, &pos);
    printf("%d", extract_nibbles(reg, pos));
    return 0;
}