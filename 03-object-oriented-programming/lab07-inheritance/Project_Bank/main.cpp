#include <iostream>
#include <sstream> // Thêm thư viện này
#include "bus/MockProvider.h"
#include "ui/MoneyFormatter.h"

using namespace std;

int main() {
    MockProvider provider;

    cout << "Original Accounts:\n";
    auto accounts = provider.getAccounts();
    int amount = 70000;

    for (auto& account : accounts) {
        ostringstream output;
        output << account.name() << " has " << MoneyFormatter::format(account.balance()) 
               << ", can withdraw " << MoneyFormatter::format(account.withdraw(amount)) << "\n";
        cout << output.str();
    }

    cout << "\nAccounts with BankAccount2 constraints:\n";
    auto accountsV2 = provider.getAccountsV2();
    for (auto& account : accountsV2) {
        ostringstream output;
        output << account.name() << " has " << MoneyFormatter::format(account.balance()) 
               << ", can withdraw " << MoneyFormatter::format(account.withdraw(amount)) << "\n";
        cout << output.str();
    }

    return 0;
}
