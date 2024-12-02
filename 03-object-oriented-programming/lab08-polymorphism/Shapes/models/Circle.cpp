#include "Circle.h"
#include <sstream>
#include <cmath>

Circle::Circle(double radius) : _radius(radius) {}

double Circle::area() const {
    return 3.14 * _radius * _radius;
}

double Circle::perimeter() const {
    return 2 * 3.14 * _radius;
}

std::string Circle::toString() const {
    std::ostringstream oss;
    oss << "Circle r=" << _radius;
    return oss.str();
}
