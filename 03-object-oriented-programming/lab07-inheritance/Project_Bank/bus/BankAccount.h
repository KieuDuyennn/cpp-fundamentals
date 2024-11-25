#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

// Base class BankAccount
class BankAccount {
protected:
    string _name;
    int _balance;
public:
    string name() const;
    int balance() const;

    BankAccount();
    BankAccount(string name, int balance);

    virtual int withdraw(int amount);
};

#endif
