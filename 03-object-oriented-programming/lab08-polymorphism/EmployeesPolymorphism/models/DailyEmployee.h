#ifndef DAILYEMPLOYEE_H
#define DAILYEMPLOYEE_H

#include "Employee.h"
#include <string>

class DailyEmployee : public Employee {
public:
    DailyEmployee(int dayCount, int paymentPerDay);
    int salary() const override;
    std::string toString() const override;

private:
    int _dayCount;
    int _paymentPerDay;
};

#endif // DAILYEMPLOYEE_H
