#include <iostream>

bool isPrimeHelper(int n, int divisor) {
    // Base cases
    if (n <= 2) {
        return (n == 2);
    }
    if (n % divisor == 0) {
        return false;
    }
    if (divisor * divisor > n) {
        return true;
    }


    return isPrimeHelper(n, divisor + 1);
}

bool isPrime(int n) {
   
    if (n <= 1) {
        return false;
    }
   
    return isPrimeHelper(n, 2);
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (isPrime(number)) {
        std::cout << number << " is a prime number." << std::endl;
    } else {
        std::cout << number << " is not a prime number." << std::endl;
    }

    return 0;
}
