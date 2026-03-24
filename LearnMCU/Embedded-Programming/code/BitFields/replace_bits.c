#include <stdio.h>
#include <stdint.h>

uint32_t replace_field(uint32_t reg, uint32_t val, uint8_t pos, uint8_t len) {
    // Step 1: Clear the target field using a mask
    uint32_t mask = ((1U << len) - 1) << pos;
    reg &= ~mask;

    // Step 2: Shift the new value and OR it into position
    reg |= (val & ((1U << len) - 1)) << pos;

    return reg;
}

int main() {
    uint32_t reg, val;
    uint8_t pos, len;
    scanf("%u %u %hhu %hhu", &reg, &val, &pos, &len);
    printf("%u", replace_field(reg, val, pos, len));
    return 0;
}