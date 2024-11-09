#include "SolidRectangleConverter.h"

SolidRectangleConverter::SolidRectangleConverter(const std::string& fillChar) : _fillChar(fillChar) {}

std::string SolidRectangleConverter::convert(const Rectangle& rectangle) const {
    std::string result;
    for (int i = 0; i < rectangle.getHeight(); ++i) {
        result += std::string(rectangle.getWidth(), _fillChar[0]) + "\n";
    }
    return result;
}
