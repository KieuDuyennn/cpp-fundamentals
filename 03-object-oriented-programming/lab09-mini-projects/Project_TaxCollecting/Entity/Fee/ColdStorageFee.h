#ifndef COLDSTORAGEFEE_H
#define COLDSTORAGEFEE_H

#include "IFee.h"

class ColdStorageFee : public IFee {
private:
    int _fee;
public:
    ColdStorageFee(int fee);
    int calculateFee() override;
    std::string toString() override;
};
#endif
