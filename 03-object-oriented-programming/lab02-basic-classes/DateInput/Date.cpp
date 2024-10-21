#include "Date.h"
#include <iostream>

Date::Date(int day, int month, int year) : Day(day), Month(month), Year(year) {}

void Date::print() const {
    std::cout << "Date: " << Day << "/" << Month << "/" << Year << "\n";
}
