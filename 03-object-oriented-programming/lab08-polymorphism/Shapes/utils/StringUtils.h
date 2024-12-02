#pragma once
#include <string>
#include <vector>

namespace Utils {
    class StringUtils {
    public:
        // Splits a string into a vector of tokens based on the given delimiter
        static std::vector<std::string> split(const std::string& str, const std::string& delimiter);
    };
}
