#ifndef POINTTOSTRINGCONVERTER_H
#define POINTTOSTRINGCONVERTER_H

#include <string>
#include "Point.h"

class PointToStringConverter {
public:
    std::string convert(Point point) {
        return "(" + point.getX() + ", " + point.getY() + ")";
    }
};

#endif // POINTTOSTRINGCONVERTER_H
