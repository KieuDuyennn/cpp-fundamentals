#ifndef NUMBERFORMATINFO_H
#define NUMBERFORMATINFO_H

#include "../models/Object.h"
#include <string>

class NumberFormatInfo : public Object {
private:
    std::string _currencyDecimalSeparator = ".";
    std::string _currencySymbol = "d";
    int _currencyPositive = 3; // 0, 1, 2, 3
    std::string _currencyPositiveFormat = "n $"; // "$n", "n$", "$ n", "n $"

public:
    std::string currencyDecimalSeparator() const;
    std::string currencySymbol() const;
    int currencyPositive() const;
    std::string currencyPositiveFormat() const;
    std::string toString() const override;
};

#endif // NUMBERFORMATINFO_H
