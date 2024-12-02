#pragma once
#include "IDao.h"
#include <vector>

class MockDao : public IDao {
public:
    void save(const std::vector<IShape*>& shapes) override;
    std::vector<IShape*> load() override;
};
