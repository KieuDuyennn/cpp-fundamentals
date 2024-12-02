#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Object.h"
#include <string>

class Employee : public Object {
public:
    virtual ~Employee() = default;
    virtual int salary() const = 0;
    virtual std::string toString() const = 0;
};

#endif // EMPLOYEE_H
