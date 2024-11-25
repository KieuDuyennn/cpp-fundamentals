#ifndef BANKACCOUNT2_H
#define BANKACCOUNT2_H

#include "BankAccount.h"

// Derived class BankAccount2
class BankAccount2 : public BankAccount {
public:
    BankAccount2();
    BankAccount2(string name, int balance);

    int withdraw(int amount) override;
};

#endif
