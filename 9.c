 #include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 20, b = 28;
    int result = gcd(a, b);
    printf("GCD of %d and %d is %d\n", a, b, result);

    return 0;
}


