#ifndef DATETOSTRINGCONVERTER_H
#define DATETOSTRINGCONVERTER_H

#include <string>
#include <iomanip>
#include <sstream>
#include "Date.h"

class DateToStringConverter {
public:
    std::string convert(const Date& date) {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << date.getDay() << "/"
            << std::setw(2) << std::setfill('0') << date.getMonth() << "/"
            << date.getYear();
        return oss.str();
    }
};

#endif // DATETOSTRINGCONVERTER_H
