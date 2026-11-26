#ifndef INTTOCURRENCYCONVERTER_H
#define INTTOCURRENCYCONVERTER_H

#include "IConverter.h"
#include "../Entity/Booth/Integer.h"
#include "../Entity/Booth/NumberFormatInfo.h"
#include <sstream>
#include <algorithm>
#include <regex>

#include "IConverter.h"

class IntToCurrencyConverter : public IConverter {
public:
    std::string convert(const std::vector<IBaseBooth*>& booths) override;
    std::string convert(Object* object) ;
    std::string toString() override;
};

#endif // INTTOCURRENCYCONVERTER_H
