#ifndef JEWELRYBOOTH_H
#define JEWELRYBOOTH_H

#include "IBaseBooth.h"

class JewelryBooth : public IBaseBooth {
private:
    std::string _id;
    int _area;
    int _securityFee;
public:
    JewelryBooth(std::string id, int area, int securityFee);
    std::string getId() override;
    std::string getType() override;
    int getArea() override;
    int calculateBaseRent() override;
    int calculateAdditionalFee() override;
    int calculateTotalRent() override;
    std::string toString() override;
};

#endif // JEWELRYBOOTH_H
