#include "main.h"

int main() {
    long long moneyVND;
    double exchangeRate;

    cout << "Enter money in VND (between 1,000,000 and 10,000,000): ";
    cin >> moneyVND;

    while (moneyVND < 1000000 || moneyVND > 10000000) {
        cout << "Invalid amount of money. Enter money in the range [1,000,000 - 10,000,000]: ";
        cin >> moneyVND;
    }

    cout << "Enter the exchange rate for 1 USD: ";
    cin >> exchangeRate;

    while (exchangeRate <= 0) {
        cout << "Invalid exchange rate. Enter a positive value: ";
        cin >> exchangeRate;
    }

    double moneyUSD = moneyVND / exchangeRate;

    cout << fixed << setprecision(2);
    cout << moneyVND << " VND = $" << moneyUSD << endl;
    return 0;
}
