#ifndef FRACTIONCONVERTER_H
#define FRACTIONCONVERTER_H

#include "../../lib/Fraction.h"
#include <string>

class FractionConverter {
public:
    static std::string toMixedNumber(const Fraction& fraction);
    static double toDecimal(const Fraction& fraction);
    static std::string toPercentage(const Fraction& fraction);
};

#endif
