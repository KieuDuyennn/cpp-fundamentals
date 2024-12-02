#ifndef ICONVERTER_H
#define ICONVERTER_H

#include "../../models/Object.h"

class IConverter {
public:
    virtual ~IConverter() = default;
    virtual std::string convert(Object* object) const = 0;
};

#endif // ICONVERTER_H
