#ifndef MOCKPROVIDER_H
#define MOCKPROVIDER_H

#include <vector>
#include "BankAccount.h"
#include "BankAccount2.h"

class MockProvider {
public:
    vector<BankAccount> getAccounts();
    vector<BankAccount2> getAccountsV2();
};

#endif
