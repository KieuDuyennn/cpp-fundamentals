#ifndef SECURITYFEE_H
#define SECURITYFEE_H

#include "IFee.h"

class SecurityFee : public IFee {
private:
    int _fee;
public:
    SecurityFee(int fee);
    int calculateFee() override;
    std::string toString() override;
};

#endif // SECURITYFEE_H
