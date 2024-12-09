#ifndef FOODBOOTH_H
#define FOODBOOTH_H

#include "IBaseBooth.h"

class FoodBooth : public IBaseBooth {
private:
    std::string _id;
    int _area;
    int _coldStorageFee;
public:
    FoodBooth(std::string id, int area, int coldStorageFee);
    std::string getId() override;
    std::string getType() override;
    int getArea() override;
    int calculateBaseRent() override;
    int calculateAdditionalFee() override;
    int calculateTotalRent() override;
    std::string toString() override;
};

#endif // FOODBOOTH_H
