#include "IntegersTextProvider.h"
#include <fstream>
#include <iostream>

std::vector<int> IntegersTextProvider::read(const std::string& filename) {
    std::vector<int> numbers;
    std::ifstream file(filename);
    int number;
    
    if (!file) {
        std::cerr << "Could not open file: " << filename << "\n";
        return numbers;
    }

    while (file >> number) {
        numbers.push_back(number);
    }

    return numbers;
}
