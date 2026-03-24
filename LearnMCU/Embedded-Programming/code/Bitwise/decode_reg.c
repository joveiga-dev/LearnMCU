/*
11. Decode Status Register into Human-Readable Flags
    Accepts a uint8_t status_reg
    Decodes which flags are set (bits = 1)
    Prints only the enabled flag names, one per line, in the order of bits from LSB to MSB (0 to 7)
*/

#include <stdio.h>
#include <stdint.h>

void decode_status(uint8_t status_reg) {
    // Your logic here
    // Bit_0 Power On
    // Bit_1 Error
    // Bit_2 Tx Ready
    // Bit_3 Rx Ready
    // Bit_4 overheat
    // Bit_5 Undervoltage
    // Bit_6 Timeout
    // Bit_7 Reserved

    const char *flags[8] = {
        "Power On",
        "Error",
        "Tx Ready",
        "Rx Ready",
        "Overheat",
        "Undervoltage",
        "Timeout",
        "Reserved"
    };


    for(int i = 0; i < 8; i++) {
        if(status_reg & (1 << i)) { // check which bit is set
            printf("%s\n", flags[i]);
        }
    }

}

int main() {
    uint8_t reg;
    scanf("%hhu", &reg);
    decode_status(reg);
    return 0;
}