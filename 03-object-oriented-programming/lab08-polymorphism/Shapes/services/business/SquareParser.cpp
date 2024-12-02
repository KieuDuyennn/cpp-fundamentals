#include "SquareParser.h"
#include "../../models/Square.h"
#include <sstream>

IShape* SquareParser::parse(const std::string& data) const {
    double side = 0;
    std::istringstream iss(data);
    iss.ignore(2); // Skip "a="
    iss >> side;
    return new Square(side);
}
