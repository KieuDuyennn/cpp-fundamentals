#include <iostream>
#include <string>

std::string toBinary(int x) {
    if (x == 0) return "0";
    if (x == 1) return "1";
    
    std::string binary;
    while (x > 0) {
        binary = char('0' + (x % 2)) + binary;
        x /= 2;
    }
    return binary;
}

int main() {
    int number;
    std::cout << "Nhap n: ";
    std::cin >> number;
    std::cout << "Bieu dien nhi phan: " << toBinary(number) << std::endl;
    
    return 0;
}

