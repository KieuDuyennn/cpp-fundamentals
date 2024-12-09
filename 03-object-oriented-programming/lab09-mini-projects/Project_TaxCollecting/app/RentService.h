#ifndef RENTSERVICE_H
#define RENTSERVICE_H

#include <vector>
#include <string>
#include "../Entity/Booth/IBaseBooth.h"

#include "../data/RealDao.h"
#include "../ui/FeeToTableFormatter.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include "../Entity/Booth/IBaseBooth.h"

class RentService {
public:
    void processRentData(const std::string& inputFilePath, const std::string& outputFilePath);
private:
    std::vector<IBaseBooth*> parseRentData(const std::string& inputFilePath);
    void generateReport(const std::vector<IBaseBooth*>& booths, const std::string& outputFilePath);
};

#endif // RENTSERVICE_H
