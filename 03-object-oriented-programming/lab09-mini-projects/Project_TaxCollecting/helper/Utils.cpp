#include "Utils.h"

std::vector<std::string> Utils::String::split(std::string haystack, std::string needle) {
    std::vector<std::string> result;
    size_t startPos = 0;
    size_t foundPos = haystack.find(needle, startPos);

    while (foundPos != std::string::npos) {
        size_t count = foundPos - startPos;
        std::string token = haystack.substr(startPos, count);
        result.push_back(token);

        startPos = foundPos + needle.length();
        foundPos = haystack.find(needle, startPos);
    }

    // The remaining part
    std::string token = haystack.substr(startPos, haystack.length() - startPos);
    result.push_back(token);

    return result;
}
