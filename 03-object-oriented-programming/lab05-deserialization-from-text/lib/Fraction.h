#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <numeric>
#include "../lib/Result.h"

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1);
    void simplify();
    std::string toString() const;
    int getNumerator() const;
    int getDenominator() const;

    static Result<Fraction> parse(const std::string& str);
};

#endif
