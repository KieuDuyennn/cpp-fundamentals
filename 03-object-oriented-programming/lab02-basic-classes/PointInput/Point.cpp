#include "Point.h"

Point::Point(float x, float y) : X(x), Y(y) {}

void Point::print() const {
    std::cout << "The point is: (" << X << ", " << Y << ")\n";
}
