#ifndef CLOTHESBOOTH_H
#define CLOTHESBOOTH_H

#include "IBaseBooth.h"

class ClothesBooth : public IBaseBooth {
private:
    std::string _id;
    int _area;
public:
    ClothesBooth(std::string id, int area);
    std::string getId() override;
    std::string getType() override;
    int getArea() override;
    int calculateBaseRent() override;
    int calculateAdditionalFee() override;
    int calculateTotalRent() override;
    std::string toString() override;
};

#endif // CLOTHESBOOTH_H
