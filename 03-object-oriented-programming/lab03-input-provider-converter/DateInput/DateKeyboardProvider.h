#ifndef DATEKEYBOARDPROVIDER_H
#define DATEKEYBOARDPROVIDER_H

#include <iostream>
#include <regex>
#include "Date.h"

class DateKeyboardProvider {
public:
    Date next(const std::string& prompt) {
        std::string input;
        std::regex date_pattern(R"((\d{1,2})/(\d{1,2})/(\d{4}))");
        std::smatch matches;

        while (true) {
            std::cout << prompt << std::endl;
            std::cin >> input;

            if (std::regex_match(input, matches, date_pattern)) {
                int day = std::stoi(matches[1]);
                int month = std::stoi(matches[2]);
                int year = std::stoi(matches[3]);

                // Validate the date
                if (isValidDate(day, month, year)) {
                    Date date(day, month, year);
                    return date;
                } else {
                    std::cout << "Invalid date. Please enter a valid date." << std::endl;
                }
            } else {
                std::cout << "Invalid date format. Please use dd/mm/yyyy." << std::endl;
            }
        }
    }

private:
    bool isValidDate(int day, int month, int year) {
        // Check month range
        if (month < 1 || month > 12) return false;

        // Days in each month
        int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Adjust for leap year in February
        if (isLeapYear(year)) {
            daysInMonth[1] = 29;  // February has 29 days in a leap year
        }

        // Check day range
        return (day >= 1 && day <= daysInMonth[month - 1]);
    }

    bool isLeapYear(int year) {
        // A year is a leap year if:
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

#endif // DATEKEYBOARDPROVIDER_H
