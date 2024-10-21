#include "Student.h"

Student::Date::Date(int day, int month, int year) : Day(day), Month(month), Year(year) {}

void Student::Date::print() const {
    std::cout << Day << "/" << Month << "/" << Year;
}

Student::Student(std::string id, std::string fullname, std::string address, std::string email, Date dob)
    : ID(id), Fullname(fullname), Address(address), Email(email), DOB(dob) {}

void Student::print() const {
    std::cout << "ID: " << ID << "\n"
              << "Full Name: " << Fullname << "\n"
              << "Address: " << Address << "\n"
              << "Email: " << Email << "\n"
              << "Date of Birth: ";
    DOB.print();
    std::cout << "\n";
}
