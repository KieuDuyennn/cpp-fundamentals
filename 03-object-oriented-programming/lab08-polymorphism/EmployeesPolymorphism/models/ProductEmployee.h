#ifndef PRODUCTEMPLOYEE_H
#define PRODUCTEMPLOYEE_H

#include "Employee.h"
#include <string>

class ProductEmployee : public Employee {
public:
    ProductEmployee(int productCount, int paymentPerProduct);
    int salary() const override;
    std::string toString() const override;

private:
    int _productCount;
    int _paymentPerProduct;
};

#endif // PRODUCTEMPLOYEE_H
