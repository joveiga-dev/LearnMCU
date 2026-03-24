/**
 * You are given a block of memory (array of n bytes) which includes n-1 data bytes and 
 * the last byte as checksum.

Your task is to verify whether the last byte equals the XOR of all previous bytes (excluding itself).

Return:

    1 if the checksum is valid
    0 if the checksum is incorrect

Checksum: It’s a simple error-detection method that ensures data hasn’t been corrupted during storage or transmission.

The sender calculates based on specific algorithm and sends it with the data; the receiver recalculates it similarly from the received data—if both match, the data is intact, otherwise it’s likely corrupted.

Some methods used are 
    Simple Sum Add all bytes, keep only the lowest 8 or 16 bits.
    XOR Checksum: XOR all bytes of data.
    CRC (Cyclic Redundancy Check): more accurate, etc
 */

 #include <stdio.h>

int validate_checksum(int *mem, int n) {
    int *ptr = mem;
    int xor_result = 0;

    for (int i = 0; i < n - 1; i++) {
        xor_result ^= *ptr;
        ptr++;
    }

    int checksum = *ptr;  // last byte is the checksum
    return xor_result == checksum ? 1 : 0;
}

int main() {
    int n, arr[100];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = validate_checksum(arr, n);
    printf("%d", result);

    return 0;
}
