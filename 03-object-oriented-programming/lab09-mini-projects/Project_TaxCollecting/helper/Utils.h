#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

namespace Utils {
    class String {
    public:
        static std::vector<std::string> split(std::string haystack, std::string needle);
    };
}

#endif // UTILS_H
