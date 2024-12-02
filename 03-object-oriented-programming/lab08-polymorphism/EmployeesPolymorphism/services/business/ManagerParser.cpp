#include "ManagerParser.h"
#include <sstream>

Employee* ManagerParser::parse(const std::string& data) const {
    int employeeCount, paymentPerEmployee, baseSalary;
    char delimiter;

    std::istringstream iss(data);
    iss.ignore(15, '=') >> employeeCount >> delimiter >> paymentPerEmployee >> delimiter >> baseSalary;

    return new Manager(employeeCount, paymentPerEmployee, baseSalary);
}
