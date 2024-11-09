#include <iostream>
#include <vector>
#include "bus/FractionKeyboardProvider.h"
#include "../lib/RandomInteger.h"
#include "../lib/DynamicArray.h"
#include "ui/FractionConverter.h"

int main() {
    RandomInteger random;
    FractionKeyboardProvider provider;
    DynamicArray<Fraction> fractions;

    int n = random.next(10, 20);
    std::cout << "Please enter " << n << " fractions from the keyboard:\n";

    for (int i = 1; i <= n; ++i) {
        Result<Fraction> result = provider.next();
        if (!result.success) {
            std::cout << "Error: " << result.message << ". Please enter again.\n";
            --i;
        } else {
            fractions.add(result.data);
        }
    }

    std::cout << "All entered fractions: ";
    for (int i = 0; i < fractions.size(); ++i) {
        std::cout << FractionConverter::toMixedNumber(fractions.get(i));
        if (i < fractions.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}
