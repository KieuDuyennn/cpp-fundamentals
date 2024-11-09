#ifndef SOLIDRECTANGLECONVERTER_H
#define SOLIDRECTANGLECONVERTER_H

#include <string>
#include "../../lib/Rectangle.h"

class SolidRectangleConverter {
private:
    std::string _fillChar;

public:
    SolidRectangleConverter(const std::string& fillChar);
    std::string convert(const Rectangle& rectangle) const;
};

#endif 
