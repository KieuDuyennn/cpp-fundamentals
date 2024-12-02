#pragma once
#include "IDao.h"
#include <vector>
#include <string>

class RealDao : public IDao {
private:
    std::string _filePath;

public:
    RealDao(const std::string& filePath);
    void save(const std::vector<IShape*>& shapes) override;
    std::vector<IShape*> load() override;
};
