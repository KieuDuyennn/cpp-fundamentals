#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("data.txt");
    
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::cout << "Reading data.txt..." << std::endl;

    std::string line;
    std::getline(file, line);
    
    std::stringstream ss(line);
    std::string token;
    std::vector<int> numbers;

    while (std::getline(ss, token, ',')) {
        numbers.push_back(std::stoi(token));
    }

    std::sort(numbers.begin(), numbers.end());

    std::cout << "Found " << numbers.size() << " numbers." << std::endl;

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
