#include "FractionKeyboardProvider.h"
#include <iostream>

Result<Fraction> FractionKeyboardProvider::next() {
    std::string input;
    std::cout << "Enter a fraction: ";
    std::getline(std::cin, input);
    return Fraction::parse(input);
}
