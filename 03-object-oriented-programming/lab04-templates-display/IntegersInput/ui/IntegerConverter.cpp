#include "IntegerConverter.h"
#include <sstream>
#include <limits>

Result<int> IntegerConverter::parse(const std::string& input) {
    // Check if the input is empty
    if (input.empty()) {
        return Result<int>(false, 1, "Input data is empty", 0);
    }

    // Attempt to parse the string as an integer
    std::istringstream iss(input);
    int number;
    if (!(iss >> number)) {
        return Result<int>(false, 2, "Invalid format: expected an integer", 0);
    }

    // Check for leftover characters in the stream (e.g., partial parsing like "123abc")
    char remaining;
    if (iss >> remaining) {
        return Result<int>(false, 3, "Invalid format: additional characters found", 0);
    }

    // If we have a valid integer, return success
    return Result<int>(true, 0, "Success", number);
}
