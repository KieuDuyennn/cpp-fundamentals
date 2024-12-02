#include "Manager.h"
#include <sstream>

Manager::Manager(int employeeCount, int paymentPerEmployee, int baseSalary)
    : _employeeCount(employeeCount), _paymentPerEmployee(paymentPerEmployee), _baseSalary(baseSalary) {}

int Manager::salary() const {
    return _baseSalary + _employeeCount * _paymentPerEmployee;
}

std::string Manager::toString() const {
    std::ostringstream oss;
    oss << "Manager, employeeCount: " << _employeeCount
        << ", paymentPerEmployee: " << _paymentPerEmployee
        << ", baseSalary: " << _baseSalary;
    return oss.str();
}
