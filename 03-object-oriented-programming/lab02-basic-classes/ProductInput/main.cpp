#include <iostream>
#include <string>
#include "Product.h"

int main() {
    std::string id, name;
    float price;
    int day, month, year;

    std::cout << "Enter product ID: ";
    std::cin >> id;
    std::cin.ignore();  // Clear the newline from the input buffer
    std::cout << "Enter product name: ";
    std::getline(std::cin, name);
    std::cout << "Enter product price: ";
    std::cin >> price;
    std::cout << "Enter expiry date (day month year): ";
    std::cin >> day >> month >> year;

    Product product(id, name, price, Product::Date(day, month, year));
    product.print();

    return 0;
}
