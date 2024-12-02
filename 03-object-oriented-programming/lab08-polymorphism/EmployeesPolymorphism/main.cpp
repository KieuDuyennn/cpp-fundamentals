#include <iostream>
#include <vector>
#include <string>
#include "services/factory/ParserFactory.h"
#include "services/business/DailyEmployeeParser.h"
#include "services/business/ProductEmployeeParser.h"
#include "services/business/ManagerParser.h"
#include "services/ui/IntegerToCurrencyConverter.h"
#include "models/Employee.h"
#include "models/DailyEmployee.h"
#include "models/ProductEmployee.h"
#include "models/Manager.h"
#include "utils/Integer.h"

int main() {
    ParserFactory factory;
    factory.registerWith(new DailyEmployeeParser());
    factory.registerWith(new ProductEmployeeParser());
    factory.registerWith(new ManagerParser());

    std::vector<std::string> lines = {
        "ProductEmployee productCount=790, paymentPerProduct=20000",
        "DailyEmployee dayCount=20, paymentPerPay=1000000",
        "ProductEmployee productCount=810, paymentPerProduct=19000",
        "ProductEmployee productCount=900, paymentPerProduct=18000",
        "Manager employeeCount=49, paymentPerEmployee=500000, baseSalary=6000000",
        "DailyEmployee dayCount=22, paymentPerPay=1100000",
        "Manager employeeCount=37, paymentPerEmployee=500000, baseSalary=7000000",
        "DailyEmployee dayCount=18, paymentPerPay=1500000",
        "Manager employeeCount=30, paymentPerEmployee=500000, baseSalary=5000000"
    };

    std::vector<Employee*> employees;

    for (const std::string& line : lines) {
        int splitPosition = line.find_first_of(" ");
        std::string type = line.substr(0, splitPosition);
        IParsable* parser = factory.create(type);

        std::string data = line.substr(splitPosition + 1);
        Employee* employee = parser->parse(data);
        employees.push_back(employee);
    }

    IntegerToCurrencyConverter converter;

    for (auto& employee : employees) {
        Integer* value = new Integer(employee->salary());
        std::cout << employee->toString() << ", salary: "
                  << converter.convert(value) << std::endl;
        delete value;
    }

    for (auto& employee : employees) {
        delete employee;
    }

    return 0;
}
