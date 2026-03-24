/*
Build a 16-bit control register
Field	Bits	Position (LSB-first)
ENABLE	1	Bit 0
MODE	2	Bits 1–2
SPEED	3	Bits 3–5
RESERVED	2	Bits 6–7 (must be 0)
*/

#include <stdio.h>
#include <stdint.h>

// Field-setting macros
#define SET_ENABLE(x)  ((x & 0x01) << 0)   // Bit 0
#define SET_MODE(x)    ((x & 0x03) << 1)   // Bits 1–2
#define SET_SPEED(x)   ((x & 0x07) << 3)   // Bits 3–5
// Reserved bits 6–7 left 0

// Build register using macros
uint16_t build_register(uint8_t enable, uint8_t mode, uint8_t speed) {
    uint16_t reg = 0;

    reg |= SET_ENABLE(enable);
    reg |= SET_MODE(mode);
    reg |= SET_SPEED(speed);

    return reg;
}

int main() {
    uint8_t enable, mode, speed;
    scanf("%hhu %hhu %hhu", &enable, &mode, &speed);

    uint16_t reg = build_register(enable, mode, speed);
    printf("%u", reg);
    return 0;
}