#include <iostream>
#include "bus/Provider.h"
#include "ui/FractionConverter.h"

int main() {
    std::vector<Fraction> fractions = Provider::readFractions("input.txt");

    std::cout << "Working with fraction arrays from text files\n";
    std::cout << "Reading data from input.txt.\n";
    std::cout << "Expected to find " << fractions.size() << " fractions.\n";

    if (fractions.empty()) {
        std::cout << "No fractions found in file.\n";
        return 1;
    }

    std::cout << "Found " << fractions.size() << " fractions: ";
    for (const auto& fraction : fractions) std::cout << fraction.toString() << ", ";
    std::cout << "\n";

    std::cout << "Lowest term: ";
    for (const auto& fraction : fractions) std::cout << FractionConverter::toMixedNumber(fraction) << ", ";
    std::cout << "\n";

    std::cout << "Decimal: ";
    for (const auto& fraction : fractions) std::cout << FractionConverter::toDecimal(fraction) << ", ";
    std::cout << "\n";

    std::cout << "Percentage: ";
    for (const auto& fraction : fractions) std::cout << FractionConverter::toPercentage(fraction) << ", ";
    std::cout << "\n";

    std::cout << "Program is exiting. Press enter to quit...\n";
    std::cin.get();
    return 0;
}
