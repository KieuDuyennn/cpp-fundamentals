#pragma once
#include "IShape.h"

class Square : public IShape {
private:
    double _side;

public:
    Square(double side);
    double area() const override;
    double perimeter() const override;
    std::string toString() const override;
};
