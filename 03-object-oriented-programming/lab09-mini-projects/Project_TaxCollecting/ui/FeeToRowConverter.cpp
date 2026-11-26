#include "FeeToRowConverter.h"

int FeeToRowConverter::count = 0;

// Pads a cell with spaces up to the column width. Signed math so a long value never wraps around.
static void pad(std::stringstream& builder, int width, int used) {
    for (int i = used; i < width; i++)
        builder << " ";
}

FeeToRowConverter::FeeToRowConverter(std::vector<int> columnSizes) {
    _columnSizes = columnSizes;
}

std::string FeeToRowConverter::convert(Object* object) {
    auto booth = dynamic_cast<IBaseBooth*>(object);
    if (booth == nullptr) return "";
    IntToCurrencyConverter currencyConverter;

    std::stringstream builder;

    int stt = ++FeeToRowConverter::count;

    // Format Order Column
    builder << stt;
    pad(builder, _columnSizes[0], (int)std::to_string(stt).size());

    // Format Booth ID Column
    builder << "| " << booth->getId();
    pad(builder, _columnSizes[1], (int)booth->getId().size());

    // Format Booth Type Column
    builder << "| " << booth->getType();
    pad(builder, _columnSizes[2], (int)booth->getType().size());

    // Format Area Column
    builder << "| " << booth->getArea() << " m2";
    pad(builder, _columnSizes[3], (int)std::to_string(booth->getArea()).size() + 3);

    // Format Rent per m2 Column
    builder << "| 560.000";
    pad(builder, _columnSizes[4], 7);

    // Format Base Rent Column
    Integer baseRent(booth->calculateBaseRent());
    std::string baseRentStr = currencyConverter.convert(&baseRent);
    builder << "| " << baseRentStr;
    pad(builder, _columnSizes[5], (int)baseRentStr.size());

    // Format Additional Fee Column
    Integer additionalFee(booth->calculateAdditionalFee());
    std::string additionalFeeStr = currencyConverter.convert(&additionalFee);
    builder << "| " << additionalFeeStr;
    pad(builder, _columnSizes[6], (int)additionalFeeStr.size());

    // Format Total Rent Column
    Integer totalRent(booth->calculateTotalRent());
    std::string totalRentStr = currencyConverter.convert(&totalRent);
    builder << "| " << totalRentStr;

    return builder.str();
}

std::string FeeToRowConverter::convert(const std::vector<IBaseBooth*>& /*booths*/) {
    // This method is not applicable for FeeToRowConverter
    return "";
}

std::string FeeToRowConverter::toString() {
    return "FeeToRowConverter";
}
