/**
 * You are given an 8-bit register and a number of positions n. Rotate the register to the left by n bits. The rotation must be circular,
 *  meaning the leftmost bits wrap around to the right.
 * Use 0-based indexing, and return the result as an 8-bit value.
 * 
 */

 #include <stdio.h>
#include <stdint.h>

uint8_t rotate_left(uint8_t reg, uint8_t n) {
    // rotate to circular sleft
    uint8_t result = (reg << n) | (reg >> (8 - n));
    result &= 0xFF;
    return result;
}

int main() {
    uint8_t reg, n;
    scanf("%hhu %hhu", &reg, &n);
    printf("%u", rotate_left(reg, n));
    return 0;
}