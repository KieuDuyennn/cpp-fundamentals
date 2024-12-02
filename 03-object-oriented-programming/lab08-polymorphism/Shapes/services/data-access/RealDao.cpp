#include "RealDao.h"
#include <fstream>
#include <iostream>

RealDao::RealDao(const std::string& filePath) : _filePath(filePath) {}

void RealDao::save(const std::vector<IShape*>& shapes) {
    std::ofstream outFile(_filePath);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for saving." << std::endl;
        return;
    }

    for (const auto& shape : shapes) {
        outFile << shape->toString() << " (area: " << shape->area()
                << ", perimeter: " << shape->perimeter() << ")" << std::endl;
    }

    outFile.close();
    std::cout << "Shapes saved to " << _filePath << "." << std::endl;
}

std::vector<IShape*> RealDao::load() {
    std::ifstream inFile(_filePath);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file for loading." << std::endl;
        return {};
    }

    std::vector<IShape*> shapes;
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << "Loaded shape: " << line << std::endl; // Just logging for now
    }

    inFile.close();
    return shapes;
}
