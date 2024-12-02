#include "DailyEmployee.h"
#include <sstream>

DailyEmployee::DailyEmployee(int dayCount, int paymentPerDay)
    : _dayCount(dayCount), _paymentPerDay(paymentPerDay) {}

int DailyEmployee::salary() const {
    return _dayCount * _paymentPerDay;
}

std::string DailyEmployee::toString() const {
    std::ostringstream oss;
    oss << "DailyEmployee, dayCount: " << _dayCount
        << ", paymentPerDay: " << _paymentPerDay;
    return oss.str();
}
