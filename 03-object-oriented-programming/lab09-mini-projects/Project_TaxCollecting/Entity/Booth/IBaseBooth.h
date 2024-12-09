#ifndef IBASEBOOTH_H
#define IBASEBOOTH_H

#include "../Object.h"
#include <string>

class IBaseBooth : public Object {
public:
    virtual std::string getId() = 0;
    virtual std::string getType() = 0;
    virtual int getArea() = 0;
    virtual int calculateBaseRent() = 0;
    virtual int calculateAdditionalFee() = 0;
    virtual int calculateTotalRent() = 0;
};

#endif // IBASEBOOTH_H
