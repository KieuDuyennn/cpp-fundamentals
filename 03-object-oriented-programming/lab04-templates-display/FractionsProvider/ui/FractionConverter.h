#ifndef FRACTIONCONVERTER_H
#define FRACTIONCONVERTER_H

#include "../../lib/Fraction.h"
#include <string>

class FractionConverter {
public:
    static std::string toMixedNumber(const Fraction& fraction);
};

#endif
