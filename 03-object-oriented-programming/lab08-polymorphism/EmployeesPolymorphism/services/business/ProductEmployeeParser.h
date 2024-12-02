#ifndef PRODUCTEMPLOYEEPARSER_H
#define PRODUCTEMPLOYEEPARSER_H

#include "IParsable.h"
#include "../../models/ProductEmployee.h"

class ProductEmployeeParser : public IParsable {
public:
    Employee* parse(const std::string& data) const override;
    std::string parsedObjectName() const override { return "ProductEmployee"; }
};

#endif // PRODUCTEMPLOYEEPARSER_H
