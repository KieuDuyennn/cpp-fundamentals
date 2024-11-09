#ifndef INTEGERCONVERTER_H
#define INTEGERCONVERTER_H

#include "../../lib/Result.h"
#include <string>

class IntegerConverter {
public:
  
    static Result<int> parse(const std::string& input);
};

#endif
