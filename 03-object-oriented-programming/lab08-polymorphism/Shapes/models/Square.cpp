#include "Square.h"
#include <sstream>

Square::Square(double side) : _side(side) {}

double Square::area() const {
    return _side * _side;
}

double Square::perimeter() const {
    return 4 * _side;
}

std::string Square::toString() const {
    std::ostringstream oss;
    oss << "Square a=" << _side;
    return oss.str();
}
