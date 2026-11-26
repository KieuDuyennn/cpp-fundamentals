#include "IntToCurrencyConverter.h"

std::string IntToCurrencyConverter::convert(Object* object) {
    auto number = dynamic_cast<Integer*>(object);
    if (number == nullptr) return "";
    long long value = number->value();
    bool negative = value < 0;
    if (negative) value = -value;

    std::stringstream builder;
    NumberFormatInfo info;
    int count = 0;
    do {
        if (count == 3) {
            builder << info.currencyDecimalSeparator();
            count = 0;
        }
        builder << value % 10;
        count++;
        value /= 10;
    } while (value != 0);
    if (negative) builder << '-';

    std::string numberSeparated = builder.str();
    std::reverse(numberSeparated.begin(), numberSeparated.end());

    std::string format = info.currencyPositiveFormat();
    std::string symbol = info.currencySymbol();

    std::string result = std::regex_replace(format, std::regex("n"), numberSeparated);
    result = std::regex_replace(result, std::regex("\\$"), symbol);

    return result;
}

std::string IntToCurrencyConverter::convert(const std::vector<IBaseBooth*>& /*booths*/) {
    // This method is not applicable for IntToCurrencyConverter
    return "";
}

std::string IntToCurrencyConverter::toString() {
    return "IntToCurrencyConverter";
}
