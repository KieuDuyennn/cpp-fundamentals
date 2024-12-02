#pragma once
#include "../../models/IShape.h"
#include <string>

class IParsable {
public:
    virtual IShape* parse(const std::string& data) const = 0;
    virtual ~IParsable() {}
};
