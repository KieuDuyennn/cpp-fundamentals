#include "BankAccount2.h"

BankAccount2::BankAccount2() : BankAccount() {}
BankAccount2::BankAccount2(string name, int balance) : BankAccount(name, balance) {}

int BankAccount2::withdraw(int amount) {
    // Kiểm tra số tiền rút phải chia hết cho 50.000 và số dư sau khi rút >= 50.000
    if (amount % 50000 == 0 && (_balance - amount) >= 50000) {
        _balance -= amount;
        return amount;
    }
    return 0;
}
