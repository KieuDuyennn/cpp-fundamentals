#include "Provider.h"
#include <fstream>
#include <iostream>

std::vector<Fraction> Provider::readFractions(const std::string& filename) {
    std::vector<Fraction> fractions;
    std::ifstream inputFile(filename);
    
    if (!inputFile) {
        std::cerr << "Could not open file: " << filename << "\n";
        return fractions;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        auto result = Fraction::parse(line);  // Sử dụng parse để đọc phân số
        if (result.success) {
            Fraction fraction = result.data;  // Lấy giá trị phân số hợp lệ
            fractions.push_back(fraction);
        } else {
            std::cerr << "Error parsing fraction: " << result.message << " (" << line << ")\n";
        }
    }
    
    inputFile.close();
    return fractions;
}
