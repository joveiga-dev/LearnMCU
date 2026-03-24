/*
2. Check if K-th Bit is Set
Check if the K-th bit (0-based index) of an integer N is set (1) or not (0).

*/

#include <stdio.h>
int isKthBitSet(int n, int k) {
   return (n & (1 << k)) ? 1 : 0;
}
int main() {
   int n, k;
   scanf("%d %d", &n, &k);
   printf("%d", isKthBitSet(n, k));
   return 0;
}