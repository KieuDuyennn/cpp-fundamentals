#include "MockProvider.h"

vector<BankAccount> MockProvider::getAccounts() {
    return vector<BankAccount> {
        BankAccount("Alice", 60000),
        BankAccount("Bob", 100000),
        BankAccount("Charlie", 100000),
        BankAccount("David", 200000),
        BankAccount("Eve", 300000),
    };
}

vector<BankAccount2> MockProvider::getAccountsV2() {
    return vector<BankAccount2> {
        BankAccount2("Alice", 60000),
        BankAccount2("Bob", 100000),
        BankAccount2("Charlie", 100000),
        BankAccount2("David", 200000),
        BankAccount2("Eve", 300000),
    };
}
