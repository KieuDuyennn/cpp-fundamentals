#include "CircleParser.h"
#include "../../models/Circle.h"
#include <sstream>

IShape* CircleParser::parse(const std::string& data) const {
    double radius = 0;
    std::istringstream iss(data);
    iss.ignore(2); // Skip "r="
    iss >> radius;
    return new Circle(radius);
}
