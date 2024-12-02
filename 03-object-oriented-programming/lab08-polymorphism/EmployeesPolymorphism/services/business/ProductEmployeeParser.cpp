#include "ProductEmployeeParser.h"
#include <sstream>

Employee* ProductEmployeeParser::parse(const std::string& data) const {
    int productCount, paymentPerProduct;
    char delimiter;

    std::istringstream iss(data);
    iss.ignore(14, '=') >> productCount >> delimiter >> paymentPerProduct;

    return new ProductEmployee(productCount, paymentPerProduct);
}
