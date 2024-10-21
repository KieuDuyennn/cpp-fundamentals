#include <iostream>
#include "Line.h"

int main() {
    float x1, y1, x2, y2;

    std::cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    Line line(x1, y1, x2, y2);
    line.print();

    return 0;
}
