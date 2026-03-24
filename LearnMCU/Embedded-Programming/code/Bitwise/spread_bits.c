/*
12. Bit Spreading Interleave Bits with Zeros
    Spread the bits such that each bit is followed by a 0
*/

#include <stdio.h>
#include <stdint.h>



uint16_t spread_bits(uint8_t val) {
    uint16_t new_val = 0;
    for(int i = 0 ; i < 8 ; i++){
        // extract i-bit
        uint8_t bit = (val >> i) & 1;
        printf("%u\n", bit); 

        if(val & (1 << i)){
            new_val |= (1 << (i * 2));
        }
    }

    return new_val;
}

int main() {
    uint8_t val;
    scanf("%hhu", &val);

    uint16_t result = spread_bits(val);
    printf("%u", result);
    return 0;
}