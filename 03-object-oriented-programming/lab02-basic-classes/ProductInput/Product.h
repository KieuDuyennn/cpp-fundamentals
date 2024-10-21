#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
public:
    std::string ID;
    std::string Name;
    float Price;

    class Date {
    public:
        int Day;
        int Month;
        int Year;

        Date(int day = 1, int month = 1, int year = 2000);
        void print() const;
    };

    Date ExpiryDate;

    Product(std::string id = "", std::string name = "", float price = 0.0f, Date expiryDate = Date());
    void print() const;
};

#endif // PRODUCT_H
