#include "Rectangle.h"

Rectangle::Rectangle(int width, int height) : _width(width), _height(height) {}

int Rectangle::getWidth() const {
    return _width;
}

int Rectangle::getHeight() const {
    return _height;
}

std::string Rectangle::toString() const {
    return "Rectangle Width=" + std::to_string(_width) + ", Height=" + std::to_string(_height);
}
