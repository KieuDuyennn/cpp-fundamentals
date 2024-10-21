#include <iostream>
#include "Point.h"

int main() {
    float x, y;

    std::cout << "Enter the coordinates of the point (x y): ";
    std::cin >> x >> y;

    Point p(x, y);
    p.print();

    return 0;
}
