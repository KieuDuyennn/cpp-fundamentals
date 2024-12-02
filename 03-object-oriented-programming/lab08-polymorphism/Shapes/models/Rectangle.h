#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
    double _width;
    double _height;

public:
    Rectangle(double width, double height);
    double area() const override;
    double perimeter() const override;
    std::string toString() const override;
};
