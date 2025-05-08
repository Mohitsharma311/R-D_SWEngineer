#include <stdio.h>

int main() {
    float real1, imag1, real2, imag2, realSum, imagSum;
    printf("Enter the real and imaginary parts of the first complex number: ");
    scanf("%f %f", &real1, &imag1);
    printf("Enter the real and imaginary parts of the second complex number: ");
    scanf("%f %f", &real2, &imag2);

    realSum = real1 + real2;
    imagSum = imag1 + imag2;
    printf("The sum of the complex numbers is: %.2f + %.2fi\n", realSum, imagSum);

    return 0;
}
 

