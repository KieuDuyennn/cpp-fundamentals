#ifndef LINEKEYBOARDPROVIDER_H
#define LINEKEYBOARDPROVIDER_H

#include <iostream>
#include "Line.h"

class LineKeyboardProvider {
public:
    Line next(std::string prompt) {
        Line line;
        std::string xStr, yStr;

        std::cout << prompt << std::endl;

        std::cout << "- Enter the start point." << std::endl;
        std::cout << "\tx: ";
        std::cin >> xStr;
        std::cout << "\ty: ";
        std::cin >> yStr;
        line.setStart(xStr, yStr);  // Store as strings

        std::cout << "- Enter the end point." << std::endl;
        std::cout << "\tx: ";
        std::cin >> xStr;
        std::cout << "\ty: ";
        std::cin >> yStr;
        line.setEnd(xStr, yStr);  // Store as strings

        return line;
    }
};

#endif // LINEKEYBOARDPROVIDER_H
