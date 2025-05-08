#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

void setup() {
    std::cout << "Enter a string: ";
}

void loop() {
    std::string input;
    std::getline(std::cin, input);
    std::reverse(input.begin(), input.end());
    for (char &ch : input) {
        ch = std::toupper(ch);
    }
    std::cout << "Reversed and Uppercased String: " << input << std::endl;
}

int main() {
    setup();
    while (true) {
        loop();
    }

    return 0;
}

