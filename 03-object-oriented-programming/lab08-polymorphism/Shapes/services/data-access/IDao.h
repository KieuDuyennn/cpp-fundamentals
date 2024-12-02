#pragma once
#include "../../models/IShape.h"
#include <vector>

class IDao {
public:
    virtual void save(const std::vector<IShape*>& shapes) = 0;
    virtual std::vector<IShape*> load() = 0;
    virtual ~IDao() {}
};
