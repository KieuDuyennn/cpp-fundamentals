#include <iostream>
#include <vector>
#include "services/factory/ParserFactory.h"
#include "utils/StringUtils.h"
#include "services/data-access/MockDao.h"

int main() {
    std::vector<std::string> lines = {
        "Square: a=12",
        "Circle: r=12",
        "Square: a=7",
        "Rectangle: w=3, h=4",
        "Rectangle: w=6, h=8",
        "Circle: r=5",
        "Square: a=8"
    };

    ParserFactory factory;
    std::vector<IShape*> shapes;

    for (const auto& line : lines) {
        auto tokens = Utils::StringUtils::split(line, ": ");
        IParsable* parser = factory.create(tokens[0]);
        if (parser) {
            shapes.push_back(parser->parse(tokens[1]));
        }
    }

    for (const auto& shape : shapes) {
        std::cout << shape->toString() << ": area=" << shape->area()
                  << ", perimeter=" << shape->perimeter() << std::endl;
    }

    // Cleanup
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
