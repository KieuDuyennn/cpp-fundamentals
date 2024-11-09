#ifndef HOLLOWRECTANGLECONVERTER_H
#define HOLLOWRECTANGLECONVERTER_H

#include <string>
#include "../../lib/Rectangle.h"

class HollowRectangleConverter {
private:
    std::string _borderChar;

public:
    HollowRectangleConverter(const std::string& borderChar);
    std::string convert(const Rectangle& rectangle) const;
};

#endif 
