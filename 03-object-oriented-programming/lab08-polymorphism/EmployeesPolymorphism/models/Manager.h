#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <string>

class Manager : public Employee {
public:
    Manager(int employeeCount, int paymentPerEmployee, int baseSalary);
    int salary() const override;
    std::string toString() const override;

private:
    int _employeeCount;
    int _paymentPerEmployee;
    int _baseSalary;
};

#endif // MANAGER_H
