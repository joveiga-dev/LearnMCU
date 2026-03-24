/**
 * You are preparing a 32-bit value to send over a communication bus. To ensure compatibility across platforms, you must convert the
 *  value into 4 bytes (big-endian order) and store them into a byte array.
 */

#include <stdio.h>
#include <stdint.h>

void convert_to_big_endian(uint32_t value, uint8_t arr[4]) {
    // Your code here
    for(int i = 0; i < 4 ; i++){
        arr[i] = (value >> (8 * (3 - i))) & 0xFF;
    } 
   
}

int main() {
    uint32_t value;
    uint8_t arr[4];
    scanf("%u", &value);
    convert_to_big_endian(value, arr);
    for (int i = 0; i < 4; i++) {
        printf("%u", arr[i]);
        if(i<3){
            printf(" ");
        }
    }
    return 0;
}