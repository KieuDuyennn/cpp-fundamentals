#include "RectangleParser.h"
#include "../../models/Rectangle.h"
#include <sstream>

IShape* RectangleParser::parse(const std::string& data) const {
    double width = 0, height = 0;
    std::istringstream iss(data);
    iss.ignore(2); // Skip "w="
    iss >> width;
    iss.ignore(4); // Skip ", h="
    iss >> height;
    return new Rectangle(width, height);
}
