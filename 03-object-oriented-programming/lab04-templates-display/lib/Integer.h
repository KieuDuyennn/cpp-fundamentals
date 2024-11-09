#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include <regex>
#include "Result.h"

class Integer {
public:
    static bool isIntegerNumberFormat(const std::string& str);
    static Result<int> parse(const std::string& str);
};

#endif
