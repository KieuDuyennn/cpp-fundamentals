#ifndef POINTKEYBOARDPROVIDER_H
#define POINTKEYBOARDPROVIDER_H

#include <iostream>
#include "Point.h"

class PointKeyboardProvider {
public:
    Point next(std::string prompt) {
        Point point;
        std::string xStr, yStr;

        std::cout << prompt << std::endl;
        std::cout << "\tx: ";
        std::cin >> xStr;
        std::cout << "\ty: ";
        std::cin >> yStr;
        point.set(xStr, yStr);  // Store as strings

        return point;
    }
};

#endif // POINTKEYBOARDPROVIDER_H
