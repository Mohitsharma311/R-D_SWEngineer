 #include <iostream>

void checkEvenOdd(int num) {
    if (num & 1) {
        std::cout << num << " is Odd" << std::endl;
    } else {
        std::cout << num << " is Even" << std::endl;
    }
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    checkEvenOdd(number);

    return 0;
}

