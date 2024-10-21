#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
public:
    std::string ID;
    std::string Fullname;
    std::string Address;
    std::string Email;

    class Date {
    public:
        int Day;
        int Month;
        int Year;

        Date(int day = 1, int month = 1, int year = 2000);
        void print() const;
    };

    Date DOB;

    Student(std::string id = "", std::string fullname = "", std::string address = "", std::string email = "", Date dob = Date());
    void print() const;
};

#endif // STUDENT_H
