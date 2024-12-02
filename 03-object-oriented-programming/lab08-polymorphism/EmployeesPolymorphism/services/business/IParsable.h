#ifndef IPARSABLE_H
#define IPARSABLE_H

#include <string>
#include "../../models/Employee.h"

class IParsable {
public:
    virtual ~IParsable() = default;
    virtual Employee* parse(const std::string& data) const = 0;
    virtual std::string parsedObjectName() const = 0;
};

#endif // IPARSABLE_H
