#include "FractionConverter.h"
#include <cmath>
#include <sstream>
#include <iomanip>

std::string FractionConverter::toMixedNumber(const Fraction& fraction) {
    int num = fraction.getNumerator();
    int denom = fraction.getDenominator();
    
    int whole = num / denom;
    int remainder = std::abs(num % denom);

    if (remainder == 0) {
        return std::to_string(whole);
    } else if (whole == 0) {
        return std::to_string(num) + "/" + std::to_string(denom);
    } else {
        return std::to_string(whole) + " " + std::to_string(remainder) + "/" + std::to_string(denom);
    }
}

double FractionConverter::toDecimal(const Fraction& fraction) {
    return static_cast<double>(fraction.getNumerator()) / fraction.getDenominator();
}

std::string FractionConverter::toPercentage(const Fraction& fraction) {
    double decimal = toDecimal(fraction) * 100;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << decimal << "%";
    return oss.str();
}
