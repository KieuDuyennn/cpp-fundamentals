#include <iostream>
#include <string>
#include "Student.h"

int main() {
    std::string id, fullname, address, email;
    int day, month, year;

    std::cout << "Enter student ID: ";
    std::cin >> id;
    std::cin.ignore();  // Clear the newline from the input buffer
    std::cout << "Enter full name: ";
    std::getline(std::cin, fullname);
    std::cout << "Enter address: ";
    std::getline(std::cin, address);
    std::cout << "Enter email: ";
    std::getline(std::cin, email);
    std::cout << "Enter date of birth (day month year): ";
    std::cin >> day >> month >> year;

    Student student(id, fullname, address, email, Student::Date(day, month, year));
    student.print();

    return 0;
}
