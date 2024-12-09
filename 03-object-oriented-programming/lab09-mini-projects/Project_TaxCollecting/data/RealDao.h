#ifndef REALDAO_H
#define REALDAO_H

#include "IDao.h"
#include "../Entity/Booth/FoodBooth.h"
#include "../Entity/Booth/ClothesBooth.h"
#include "../Entity/Booth/JewelryBooth.h"
#include "../helper/Utils.h"
#include <fstream>
#include <iostream>
class RealDao : public IDao {
public:
    std::vector<IBaseBooth*> readRentData(std::string filePath) override;
};
int stoii(const std::string& str);
#endif // REALDAO_H
