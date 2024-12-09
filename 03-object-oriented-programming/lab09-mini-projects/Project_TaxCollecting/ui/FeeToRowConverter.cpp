#include "FeeToRowConverter.h"


int FeeToRowConverter::count = 0;

FeeToRowConverter::FeeToRowConverter(std::vector<int> columnSizes) {
    _columnSizes = columnSizes;
}

std::string FeeToRowConverter::convert(Object* object) {
    auto booth = dynamic_cast<IBaseBooth*>(object);
    IntToCurrencyConverter currencyConverter;

    std::stringstream builder;

    int stt = ++FeeToRowConverter::count;

    // Format Order Column
    builder << stt;
    for (int i = 1; i <= _columnSizes[0] - std::to_string(stt).size(); i++)
        builder << " ";

    // Format Booth ID Column
    builder << "| " << booth->getId();
    for (int i = 1; i <= _columnSizes[1] - booth->getId().size(); i++)
        builder << " ";

    // Format Booth Type Column
    builder << "| " << booth->getType();
    for (int i = 1; i <= _columnSizes[2] - booth->getType().size(); i++)
        builder << " ";

    // Format Area Column
    builder << "| " << booth->getArea() << " m2";
    for (int i = 1; i <= _columnSizes[3] - std::to_string(booth->getArea()).size() - 3; i++)
        builder << " ";

    // Format Rent per m2 Column
    builder << "| 560.000";
    for (int i = 1; i <= _columnSizes[4] - 7; i++)
        builder << " ";

    // Format Base Rent Column
    Integer baseRent(booth->calculateBaseRent());
    std::string baseRentStr = currencyConverter.convert(&baseRent);
    builder << "| " << baseRentStr;
    for (int i = 1; i <= _columnSizes[5] - baseRentStr.size(); i++)
        builder << " ";

    // Format Additional Fee Column
    Integer additionalFee(booth->calculateAdditionalFee());
    std::string additionalFeeStr = currencyConverter.convert(&additionalFee);
    builder << "| " << additionalFeeStr;
    for (int i = 1; i <= _columnSizes[6] - additionalFeeStr.size(); i++)
        builder << " ";

    // Format Total Rent Column
    Integer totalRent(booth->calculateTotalRent());
    std::string totalRentStr = currencyConverter.convert(&totalRent);
    builder << "| " << totalRentStr << " d";

    return builder.str();
}

std::string FeeToRowConverter::convert(const std::vector<IBaseBooth*>& booths) {
    // This method is not applicable for FeeToRowConverter
    return "";
}

std::string FeeToRowConverter::toString() {
    return "FeeToRowConverter";
}
