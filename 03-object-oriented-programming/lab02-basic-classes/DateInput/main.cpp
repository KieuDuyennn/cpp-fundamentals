#include <iostream>
#include "Date.h"

int main() {
    int day, month, year;

    std::cout << "Enter the date (day month year): ";
    std::cin >> day >> month >> year;

    Date date(day, month, year);
    date.print();

    return 0;
}
