
#include "bus/IntegerKeyboardProvider.h"
#include "ui/IntegerConverter.h"
#include "../lib/RandomInteger.h"
#include <iostream>
#include <vector>

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {

    RandomInteger randomGen;
    int n = randomGen.next(10, 20);  
    std::cout << "Please enter " << n << " integers in the range of [20, 100]" << std::endl;

    IntegerKeyboardProvider inputProvider;
    std::vector<int> numbers;

    
    for (int i = 1; i <= n; ++i) {
        std::cout << "Integer " << i << ": ";
        Result<int> result = inputProvider.next(20, 100);  // Request integer input in the range [20, 100]
        if (!std::cin) {
            std::cout << "\nInput ended before all integers were entered." << std::endl;
            break;
        }

        if (!result.success) {
            std::cout << "Error: " << result.message << std::endl;
            --i; // Repeat this iteration if input is invalid
            continue;
        }

        numbers.push_back(result.data);
    }

    
    std::vector<int> primes;
    for (int num : numbers) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
    }

    std::cout << "Found " << primes.size() << " prime number(s): ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
