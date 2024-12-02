#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(double width, double height) : _width(width), _height(height) {}

double Rectangle::area() const {
    return _width * _height;
}

double Rectangle::perimeter() const {
    return 2 * (_width + _height);
}

std::string Rectangle::toString() const {
    std::ostringstream oss;
    oss << "Rectangle w=" << _width << ", h=" << _height;
    return oss.str();
}
