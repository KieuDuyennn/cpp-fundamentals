#include "IntegerKeyboardProvider.h"
#include "../ui/IntegerConverter.h"
#include <iostream>
#include <string>

Result<int> IntegerKeyboardProvider::next() {
    std::string input;
    std::getline(std::cin, input);
    return IntegerConverter::parse(input);
}

Result<int> IntegerKeyboardProvider::next(int min, int max) {
    std::string input;
    std::cout << "Enter an integer [" << min << ", " << max << "]: ";
    std::getline(std::cin, input);

    Result<int> result = IntegerConverter::parse(input);

    if (!result.success) {
        return result;
    }

    int number = result.data;
    if (number < min || number > max) {
        return {false, 4, "Input data is not in the required range", 0};
    }

    return result;
}
