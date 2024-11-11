#ifndef PROVIDER_H
#define PROVIDER_H

#include "../../lib/Fraction.h"
#include <string>
#include <vector>

class Provider {
public:
    // Phương thức đọc file và trả về vector chứa các phân số
    static std::vector<Fraction> readFractions(const std::string& filename);
};

#endif
