/**
 * 
 * 3. Set/Clear/toggle the Bit in an 8-bit Register
 *  Write a function to set the bit at a given position without affecting other bits..
 */

 #include <stdio.h>
#include <stdint.h>

uint8_t set_bit(uint8_t reg, uint8_t pos) {
    return reg | (1 << pos);
}

uint8_t clear_bit(uint8_t reg, uint8_t pos) {
    return reg & ~(1 << pos);
}

uint8_t toggle_bit(uint8_t reg, uint8_t pos) {
    return reg ^ (1 << pos);
}

int main() {
    uint8_t reg, pos;
    scanf("%hhu %hhu", &reg, &pos);
    uint8_t result = set_bit(reg, pos);
    printf("%u", result);
    return 0;
}