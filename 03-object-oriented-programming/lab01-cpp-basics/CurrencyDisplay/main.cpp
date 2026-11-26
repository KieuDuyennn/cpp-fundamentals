#include <limits>
#include "main.h"

int main() {
    long long moneyVND;
    double exchangeRate;

    cout << "Enter money in VND (between 1,000,000 and 10,000,000): ";
    while (!(cin >> moneyVND) || moneyVND < 1000000 || moneyVND > 10000000) {
        if (cin.eof()) return 1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid amount of money. Enter money in the range [1,000,000 - 10,000,000]: ";
    }

    cout << "Enter the exchange rate for 1 USD: ";
    while (!(cin >> exchangeRate) || exchangeRate <= 0) {
        if (cin.eof()) return 1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid exchange rate. Enter a positive value: ";
    }

    double moneyUSD = moneyVND / exchangeRate;

    cout << fixed << setprecision(2);
    cout << moneyVND << " VND = $" << moneyUSD << endl;
    return 0;
}
