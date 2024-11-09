#include "FractionConverter.h"

std::string FractionConverter::toMixedNumber(const Fraction& fraction) {
    int wholePart = fraction.getNumerator() / fraction.getDenominator();
    int remainder = fraction.getNumerator() % fraction.getDenominator();

    if (remainder == 0) {
        return std::to_string(wholePart);  // Whole number
    } else if (wholePart == 0) {
        return fraction.toString();  // Proper fraction
    } else {
        return std::to_string(wholePart) + " " + std::to_string(remainder) + "/" + std::to_string(fraction.getDenominator());
    }
}
