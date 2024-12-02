#pragma once
#include <string>

class IShape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string toString() const = 0;
    virtual ~IShape() {}
};
