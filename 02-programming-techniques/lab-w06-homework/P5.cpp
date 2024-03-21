#include <iostream>

int sumOfDigits(int x) {

    if (x < 10) {
        return x;
    }
  
    return x % 10 + sumOfDigits(x / 10);
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    int result = sumOfDigits(number);
    std::cout << "Sum of digits: " << result << std::endl;
    return 0;
}
