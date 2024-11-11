// utilities.cpp
#include "Utilities.h"
#include <cmath>
#include <string>
#include <algorithm>

bool isOdd(int number) {
    return number % 2 != 0;
}

bool isEven(int number) {
    return number % 2 == 0;
}

bool isPalindrome(int number) {
    std::string str = std::to_string(number);
    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(number); i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

bool isSquare(int number) {
    int root = static_cast<int>(std::sqrt(number));
    return root * root == number;
}

bool isPerfect(int number) {
    int sum = 1;
    for (int i = 2; i <= std::sqrt(number); ++i) {
        if (number % i == 0) {
            sum += i + (i != number / i ? number / i : 0);
        }
    }
    return sum == number && number != 1;
}
