#include "RentService.h"

void RentService::processRentData(const std::string& inputFilePath, const std::string& outputFilePath) {
    auto booths = parseRentData(inputFilePath);
    // Sort by total rent, lowest first. Sorting the raw pointers would only order them by memory address.
    std::stable_sort(booths.begin(), booths.end(), [](IBaseBooth* a, IBaseBooth* b) {
        return a->calculateTotalRent() < b->calculateTotalRent();
    });
    generateReport(booths, outputFilePath);
    for (IBaseBooth* booth : booths)
        delete booth;
}

std::vector<IBaseBooth*> RentService::parseRentData(const std::string& inputFilePath) {
    RealDao dao;
    return dao.readRentData(inputFilePath);
}

void RentService::generateReport(const std::vector<IBaseBooth*>& booths, const std::string& outputFilePath) {
    std::ofstream outFile(outputFilePath);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return;
    }

    std::vector<std::string> headers = {"STT", "Ma sap", "Loai", "Dien tich", "Tien / m2", "Tien mat bang", "Phi khac", "Tong cong"};
    std::vector<int> columnSizes = {4, 7, 10, 10, 10, 14, 12, 14};

    FeeToTableFormatter tableFormatter(headers, columnSizes);
    outFile << tableFormatter.convert(booths);
    outFile.close();
}
