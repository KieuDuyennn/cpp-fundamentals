#include "HollowRectangleConverter.h"
#include "SolidRectangleConverter.h"

HollowRectangleConverter::HollowRectangleConverter(const std::string& borderChar) : _borderChar(borderChar) {}

std::string HollowRectangleConverter::convert(const Rectangle& rectangle) const {
    std::string result;
    int width = rectangle.getWidth();
    int height = rectangle.getHeight();

    if (height < 2 || width < 2) {
        // If the rectangle is too small, make it solid
        return SolidRectangleConverter(_borderChar).convert(rectangle);
    }

    // Top border
    result += std::string(width, _borderChar[0]) + "\n";

    // Middle part with spaces in between
    for (int i = 1; i < height - 1; ++i) {
        result += _borderChar[0] + std::string(width - 2, ' ') + _borderChar[0] + "\n";
    }

    // Bottom border
    result += std::string(width, _borderChar[0]) + "\n";

    return result;
}
