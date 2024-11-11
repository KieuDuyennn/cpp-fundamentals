#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    std::string _id;
    std::string _fullname;
    std::string _email;

    Student(const std::string& id, const std::string& fullname, const std::string& email);
};

#endif 
