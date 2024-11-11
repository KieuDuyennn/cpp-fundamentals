// main.cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "bus/IntegersTextProvider.h"
#include "Utilities.h"

int main() {
    IntegersTextProvider provider;
    std::vector<int> numbers = provider.read("input.txt");

    std::cout << "Working with integer arrays from text files\n";
    std::cout << "Reading data from input.txt.\n";
    std::cout << "Expected to find " << numbers.size() << " numbers.\n";
    
    if (numbers.empty()) {
        std::cout << "No numbers found in file.\n";
        return 1;
    }
    
    std::cout << "Found " << numbers.size() << " numbers: ";
    for (int number : numbers) std::cout << number << " ";
    std::cout << "\n";

    std::vector<int> oddNumbers, evenNumbers, palindromicNumbers, primeNumbers, squareNumbers, perfectNumbers;

    for (int number : numbers) {
        if (isOdd(number)) oddNumbers.push_back(number);
        if (isEven(number)) evenNumbers.push_back(number);
        if (isPalindrome(number)) palindromicNumbers.push_back(number);
        if (isPrime(number)) primeNumbers.push_back(number);
        if (isSquare(number)) squareNumbers.push_back(number);
        if (isPerfect(number)) perfectNumbers.push_back(number);
    }

    auto printVector = [](const std::vector<int>& vec, const std::string& name) {
        std::cout << "Found " << vec.size() << " " << name << (vec.size() == 1 ? ":" : "s") << " ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
        }
        std::cout << "\n";
    };

    printVector(oddNumbers, "odd number");
    printVector(evenNumbers, "even number");
    printVector(palindromicNumbers, "palindromic number");
    printVector(primeNumbers, "prime number");
    printVector(squareNumbers, "square number");
    printVector(perfectNumbers, "perfect number");

    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal = *std::max_element(numbers.begin(), numbers.end());
    double avgVal = std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    int sumVal = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Minimum value: " << minVal << "\n";
    std::cout << "Maximum value: " << maxVal << "\n";
    std::cout << "Average value: " << avgVal << "\n";
    std::cout << "Sum of all numbers: " << sumVal << "\n";
    
    std::cout << "Program is exiting. Press enter to quit...\n";
    std::cin.get();
    return 0;
}
