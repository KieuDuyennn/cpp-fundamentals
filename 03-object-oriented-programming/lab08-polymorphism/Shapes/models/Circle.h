#pragma once
#include "IShape.h"

class Circle : public IShape {
private:
    double _radius;

public:
    Circle(double radius);
    double area() const override;
    double perimeter() const override;
    std::string toString() const override;
};
