#include <stdint.h>
#include <stdio.h>
uint32_t multiply_by_9(uint32_t n) {
    return (n << 3) + n;
}
int main(void) {
    uint32_t num = 7;
    uint32_t result = multiply_by_9(num);
    printf("Multiplying %u by 9 gives: %u\n", num, result);
    return 0;
}
