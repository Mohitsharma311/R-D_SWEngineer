#include <stdio.h>

int main(void) {
    unsigned char num;
    unsigned char bit_pos = 3;

    printf("Enter an 8-bit number (0 to 255): ");
    scanf("%hhu", &num);
    unsigned char mask = 1 << bit_pos;
    num ^= mask;

    printf("Result after toggling bit %d: %u\n", bit_pos, num);

    return 0;
}

