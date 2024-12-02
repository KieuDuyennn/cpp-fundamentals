#include "ProductEmployee.h"
#include <sstream>

ProductEmployee::ProductEmployee(int productCount, int paymentPerProduct)
    : _productCount(productCount), _paymentPerProduct(paymentPerProduct) {}

int ProductEmployee::salary() const {
    return _productCount * _paymentPerProduct;
}

std::string ProductEmployee::toString() const {
    std::ostringstream oss;
    oss << "ProductEmployee, productCount: " << _productCount
        << ", paymentPerProduct: " << _paymentPerProduct;
    return oss.str();
}
