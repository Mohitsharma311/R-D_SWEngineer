#include <stdio.h>

void decimalToBinary(int num) {
    int binary[32];
    int i = 0;
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int decimal = 545;

    printf("Decimal: %d\n", decimal);
    decimalToBinary(decimal);

    return 0;
}


