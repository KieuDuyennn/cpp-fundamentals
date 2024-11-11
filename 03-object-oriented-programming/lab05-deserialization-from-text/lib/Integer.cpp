#include "Integer.h"

bool Integer::isIntegerNumberFormat(const std::string& str) {
    std::regex pattern("^-?\\d+$");
    return std::regex_match(str, pattern);
}

Result<int> Integer::parse(const std::string& str) {
    if (str.empty()) {
        return {false, 1, "Input data is empty", 0};
    }

    if (!isIntegerNumberFormat(str)) {
        return {false, 2, "Invalid format: expected an integer", 0};
    }

    try {
        int num = std::stoi(str);
        return {true, 0, "", num};
    } catch (const std::out_of_range&) {
        return {false, 3, "Number is out of range for an integer", 0};
    }
}
