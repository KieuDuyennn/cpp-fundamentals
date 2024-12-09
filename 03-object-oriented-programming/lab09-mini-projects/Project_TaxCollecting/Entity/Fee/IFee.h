#ifndef IFEE_H
#define IFEE_H

#include "../Object.h"

class IFee : public Object {
public:
    virtual int calculateFee() = 0;
};

#endif // IFEE_H
