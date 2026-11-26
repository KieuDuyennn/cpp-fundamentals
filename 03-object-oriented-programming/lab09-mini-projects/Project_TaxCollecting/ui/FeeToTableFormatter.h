#ifndef FEETOTABLEFORMATTER_H
#define FEETOTABLEFORMATTER_H

#include "IConverter.h"
#include "../Entity/Booth/IBaseBooth.h"
#include <vector>
#include <string>
#include "FeeToRowConverter.h"
#include "IntToCurrencyConverter.h"
#include "../Entity/Booth/Integer.h"
#include <sstream>
#include <algorithm>

class FeeToTableFormatter : public IConverter {
private:
    std::vector<std::string> _headers;
    std::vector<int> _columnSizes;
public:
    FeeToTableFormatter(std::vector<std::string> headers, std::vector<int> columnSizes);
    std::string convert(const std::vector<IBaseBooth*>& booths) override;
    std::string formatTable(const std::vector<IBaseBooth*>& booths);
    std::string toString() override;
};

#endif // FEETOTABLEFORMATTER_H
