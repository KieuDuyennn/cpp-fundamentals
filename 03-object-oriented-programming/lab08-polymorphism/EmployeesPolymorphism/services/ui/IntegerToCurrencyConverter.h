#ifndef INTEGERTOCURRENCYCONVERTER_H
#define INTEGERTOCURRENCYCONVERTER_H

#include "IConverter.h"
#include "../../utils/Integer.h"
#include "../../utils/NumberFormatInfo.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>

class IntegerToCurrencyConverter : public IConverter {
public:
    std::string convert(Object* object) const override;
};

#endif // INTEGERTOCURRENCYCONVERTER_H
