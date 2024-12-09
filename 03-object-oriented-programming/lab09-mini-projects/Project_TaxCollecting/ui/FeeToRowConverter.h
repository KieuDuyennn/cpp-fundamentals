#ifndef FEETOROWCONVERTER_H
#define FEETOROWCONVERTER_H

#include "IConverter.h"
#include "../Entity/Booth/IBaseBooth.h"
#include <vector>
#include <string>
#include "IntToCurrencyConverter.h"
#include "../Entity/Booth/Integer.h"
#include <sstream>
#include <iomanip>
// class FeeToRowConverter : public IConverter {
// private:
//     std::vector<int> _columnSizes;
//     static int count;
// public:
//     FeeToRowConverter(std::vector<int> columnSizes);
//     std::string convert(Object* object) override;
//     std::string toString() override;
// };

class FeeToRowConverter : public IConverter {
private:
    std::vector<int> _columnSizes;
    static int count;
public:
    FeeToRowConverter(std::vector<int> columnSizes);
    std::string convert(Object* object);
    std::string convert(const std::vector<IBaseBooth*>& booths) override;
    std::string toString() override;
};

#endif // FEETOROWCONVERTER_H
