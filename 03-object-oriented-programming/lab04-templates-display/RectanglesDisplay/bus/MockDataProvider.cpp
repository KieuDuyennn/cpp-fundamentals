#include "MockDataProvider.h"

std::vector<Rectangle> MockDataProvider::getAllRectangles() {
    return { Rectangle(3, 4), Rectangle(4, 5), Rectangle(4, 8) };
}
