/**
 * 23. Extract and Modify Field in a 32-bit Register

In embedded systems, a 32-bit configuration register often contains several packed fields. 

Your task is to extract a 5-bit field located at bit positions 10 to 14 from a 32-bit register value. 

If this field’s value is less than 31, increment it by 1. Then write the updated value back to the same bit positions in the register, leaving all other bits unchanged.

Use only bitwise operations to extract, modify, and update the register.

Bit layout example (bit 0 is LSB):
 */

 #include <stdio.h>
#include <stdint.h>

uint32_t update_register(uint32_t reg) {
    // Your logic here
    // Extract the bit field
    uint32_t mask = (1 << 5) -1;
    uint32_t field = (reg >> 10) & mask;
    if (field < 31){
        field++;
    }
    // clear
    reg &= ~(mask << 10);
    reg |= (field & mask) << 10;
    return reg;
}

int main() {
    uint32_t reg;
    scanf("%u", &reg);
    uint32_t updated = update_register(reg);
    printf("%u", updated);
    return 0;
}