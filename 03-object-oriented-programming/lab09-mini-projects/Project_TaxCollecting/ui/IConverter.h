#ifndef ICONVERTER_H
#define ICONVERTER_H

#include "../Entity/Object.h"
#include "../Entity/Booth/IBaseBooth.h"
#include <vector>

class IConverter : public Object {
public:
    virtual std::string convert(const std::vector<IBaseBooth*>& booths) = 0;
};

#endif 
