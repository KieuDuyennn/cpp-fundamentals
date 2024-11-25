#ifndef MONEYFORMATTER_H
#define MONEYFORMATTER_H

#include <string>
#include <sstream>
#include <locale>

class MoneyFormatter {
public:
    static std::string format(int amount);
};

#endif
