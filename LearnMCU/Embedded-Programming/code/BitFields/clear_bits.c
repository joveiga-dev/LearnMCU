#include <stdio.h>
#include <stdint.h>

uint32_t clear_bits(uint32_t reg, uint8_t pos, uint8_t len) {
    // Create mask with 1s in positions to clear, then invert and AND
    uint32_t mask = ((1U << len) - 1) << pos;
    return reg & ~mask;
}

int main() {
    uint32_t reg;
    uint8_t pos, len;
    scanf("%u %hhu %hhu", &reg, &pos, &len);
    printf("%u", clear_bits(reg, pos, len));
    return 0;
}