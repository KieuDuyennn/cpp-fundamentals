#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

void printDouble(const std::string& fraction) {
    size_t slashPos = fraction.find('/');
    
    if (slashPos == std::string::npos) {
        std::cerr << "Invalid fraction format." << std::endl;
        return;
    }

    std::string numeratorStr = fraction.substr(0, slashPos);
    std::string denominatorStr = fraction.substr(slashPos + 1);

    int numerator = std::stoi(numeratorStr);
    int denominator = std::stoi(denominatorStr);

    if (denominator == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        return;
    }

    double result = static_cast<double>(numerator) / denominator;
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
}

int main() {
    std::string fraction;
    std::cout << "Enter a fraction (e.g., 12/8): ";
    std::getline(std::cin, fraction);
    printDouble(fraction);
    return 0;
}

