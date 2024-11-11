#include "../lib/Fraction.h"
#include <regex>
#include <stdexcept>
//#include <numeric>
#include <math.h>
#include <iostream>
using namespace std;

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    simplify();
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::simplify() {
    int _gcd = gcd(numerator, denominator);  // Sử dụng hàm gcd tự định nghĩa
    numerator /= _gcd;
    denominator /= _gcd;

    if (denominator < 0) { 
        numerator = -numerator;
        denominator = -denominator;
    }
}


std::string Fraction::toString() const {
    if (denominator == 1) {
        return std::to_string(numerator);
    }
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

Result<Fraction> Fraction::parse(const std::string& str) {
    if (str.empty()) {
        return {false, 1, "Input data is empty", Fraction(0, 1)};
    }

    std::regex pattern(R"(^\s*(-?\d+)\s*/\s*(-?\d+)\s*$)");
    std::smatch matches;
    if (!std::regex_match(str, matches, pattern)) {
        return {false, 2, "Invalid format: expected a fraction", Fraction(0, 1)};
    }

    try {
        int num = std::stoi(matches[1]);
        int denom = std::stoi(matches[2]);
        if (denom == 0) {
            return {false, 3, "Denominator cannot be zero", Fraction(0, 1)};
        }
        Fraction fraction(num, denom);
        return {true, 0, "", fraction};
    } catch (...) {
        return {false, 4, "Invalid numeric values", Fraction(0, 1)};
    }
}


