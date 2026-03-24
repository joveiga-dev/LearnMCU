#include <stdio.h>
#include <stdint.h>

uint32_t rotate_right(uint32_t reg, uint8_t n) {
    // Your code here
    // circular rotation to right
    uint32_t result = (reg >> n) | (reg << (32 - n));
    result &= 0xFFFFFFFF;
    return result;
}

int main() {
    uint32_t reg;
    uint8_t n;
    scanf("%u %hhu", &reg, &n);
    printf("%u", rotate_right(reg, n));
    return 0;
}