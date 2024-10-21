#include "Product.h"

Product::Date::Date(int day, int month, int year) : Day(day), Month(month), Year(year) {}

void Product::Date::print() const {
    std::cout << Day << "/" << Month << "/" << Year;
}

Product::Product(std::string id, std::string name, float price, Date expiryDate)
    : ID(id), Name(name), Price(price), ExpiryDate(expiryDate) {}

void Product::print() const {
    std::cout << "Product ID: " << ID << "\n"
              << "Name: " << Name << "\n"
              << "Price: $" << Price << "\n"
              << "Expiry Date: ";
    ExpiryDate.print();
    std::cout << "\n";
}
