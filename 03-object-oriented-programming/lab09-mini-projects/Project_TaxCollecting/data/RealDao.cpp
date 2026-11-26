#include "RealDao.h"

int stoii(const std::string& str) {
    int result = 0;
    bool isNegative = false;
    size_t i = 0;

    if (str.empty()) {
        throw std::invalid_argument("Empty string");
    }

    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    }

    for (; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            throw std::invalid_argument("Invalid character found");
        }
        result = result * 10 + (str[i] - '0');
    }

    return isNegative ? -result : result;
}

std::vector<IBaseBooth*> RealDao::readRentData(std::string filePath) {
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return {};
    }

    std::vector<IBaseBooth*> booths;
    std::string line;
    while (std::getline(inFile, line)) {
        auto tokens = Utils::String::split(line, ", ");
        if (tokens.size() < 2) continue;

        std::string type = tokens[0].substr(0, tokens[0].find(" "));
        std::string id;
        size_t idPos = tokens[0].find("ID=");
        if (idPos != std::string::npos) id = tokens[0].substr(idPos + 3);
        int area = stoii(tokens[1].substr(tokens[1].find("=") + 1));

        if (type == "Food" && tokens.size() > 2) {
            int coldStorage = stoii(tokens[2].substr(tokens[2].find("=") + 1));
            booths.push_back(new FoodBooth(id, area, coldStorage));
        } else if (type == "Clothes") {
            booths.push_back(new ClothesBooth(id, area));
        } else if (type == "Jewelry" && tokens.size() > 2) {
            int securityFee = stoii(tokens[2].substr(tokens[2].find("=") + 1));
            booths.push_back(new JewelryBooth(id, area, securityFee));
        }
    }

    inFile.close();
    return booths;
}
