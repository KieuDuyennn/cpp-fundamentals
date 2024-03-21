#include <iostream>
#include <string>

std::string toHex(int x) {
    if(x == 0) return "0";
    if(x < 0) return "Invalid Input";

    const char hexDigits[] = "0123456789ABCDEF";
    std::string hex = "";

    while(x > 0) {
        int remainder = x % 16;
        hex = hexDigits[remainder] + hex;
        x /= 16;
    }

    return hex;
}

int main() {
    int number;
    std::cout << "enter a number: ";
    std::cin >> number;

    std::cout  << toHex(number) << std::endl;

    return 0;
}
