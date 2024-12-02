#include "NumberFormatInfo.h"

std::string NumberFormatInfo::currencyDecimalSeparator() const {
    return _currencyDecimalSeparator;
}

std::string NumberFormatInfo::currencySymbol() const {
    return _currencySymbol;
}

int NumberFormatInfo::currencyPositive() const {
    return _currencyPositive;
}

std::string NumberFormatInfo::currencyPositiveFormat() const {
    return _currencyPositiveFormat;
}

std::string NumberFormatInfo::toString() const {
    return "NumberFormatInfo";
}
