#ifndef NUMBERFORMATINFO_H
#define NUMBERFORMATINFO_H

#include "../Object.h"
#include <string>

class NumberFormatInfo : public Object {
private:
    std::string _currencyDecimalSeparator = ".";
    std::string _currencySymbol = "d";
    int _currencyPositive = 3;
    std::string _currencyPositiveFormat = "n $";
public:
    std::string currencyDecimalSeparator();
    std::string currencySymbol();
    int currencyPositive();
    std::string currencyPositiveFormat();
    std::string toString() override;
};

#endif // NUMBERFORMATINFO_H
