#include <iostream>
#include "bus/MockDataProvider.h"
#include "ui/SolidRectangleConverter.h"
#include "ui/HollowRectangleConverter.h"
#include "../lib/Rectangle.h"

int main() {
    MockDataProvider provider;
    std::vector<Rectangle> rectangles = provider.getAllRectangles();
    SolidRectangleConverter solid("*");
    HollowRectangleConverter hollow("-");

    for (const auto& rectangle : rectangles) {
        std::cout << rectangle.toString() << "\n";
        std::cout << solid.convert(rectangle) << "\n";
        std::cout << hollow.convert(rectangle) << "\n";
        std::cout << "\n";
    }

    return 0;
}
