#ifndef IDAO_H
#define IDAO_H

#include "../Entity/Booth/IBaseBooth.h"
#include <vector>
#include <string>

class IDao {
public:
    virtual std::vector<IBaseBooth*> readRentData(std::string filePath) = 0;
};

#endif // IDAO_H
