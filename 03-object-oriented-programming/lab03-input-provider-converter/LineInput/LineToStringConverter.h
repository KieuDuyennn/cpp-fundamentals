#ifndef LINETOSTRINGCONVERTER_H
#define LINETOSTRINGCONVERTER_H

#include <string>
#include "Line.h"

class LineToStringConverter {
public:
    std::string convert(Line line) {
        return "((" + line.getStartX() + ", " + line.getStartY() + "), "
               "(" + line.getEndX() + ", " + line.getEndY() + "))";
    }
};

#endif // LINETOSTRINGCONVERTER_H
