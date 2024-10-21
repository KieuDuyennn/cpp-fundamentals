#include "Line.h"
#include <iostream>

Line::Line(float x1, float y1, float x2, float y2) : X1(x1), Y1(y1), X2(x2), Y2(y2) {}

void Line::print() const {
    std::cout << "Line: ((" << X1 << ", " << Y1 << "), (" << X2 << ", " << Y2 << "))\n";
}
