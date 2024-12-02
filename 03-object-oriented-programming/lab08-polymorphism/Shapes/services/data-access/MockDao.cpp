#include "MockDao.h"
#include <iostream>

void MockDao::save(const std::vector<IShape*>& shapes) {
    std::cout << "MockDao: Saving shapes..." << std::endl;
    for (const auto& shape : shapes) {
        std::cout << shape->toString() << " (area: " << shape->area()
                  << ", perimeter: " << shape->perimeter() << ")" << std::endl;
    }
}

std::vector<IShape*> MockDao::load() {
    std::cout << "MockDao: Loading shapes (not implemented)..." << std::endl;
    return {};
}
