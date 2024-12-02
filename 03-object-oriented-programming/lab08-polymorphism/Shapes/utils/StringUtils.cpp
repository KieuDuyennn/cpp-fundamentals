#include "StringUtils.h"
#include <sstream>

std::vector<std::string> Utils::StringUtils::split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t startPos = 0, foundPos;

    while ((foundPos = str.find(delimiter, startPos)) != std::string::npos) {
        tokens.push_back(str.substr(startPos, foundPos - startPos));
        startPos = foundPos + delimiter.length();
    }

    // Add the remaining part
    if (startPos < str.length()) {
        tokens.push_back(str.substr(startPos));
    }

    return tokens;
}
