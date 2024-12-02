#include "DailyEmployeeParser.h"
#include <sstream>

Employee* DailyEmployeeParser::parse(const std::string& data) const {
    int dayCount, paymentPerDay;
    char delimiter;

    std::istringstream iss(data);
    iss.ignore(10, '=') >> dayCount >> delimiter >> paymentPerDay;

    return new DailyEmployee(dayCount, paymentPerDay);
}
