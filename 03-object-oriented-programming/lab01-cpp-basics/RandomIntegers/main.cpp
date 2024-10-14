#include "main.h"

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateRandomIntegers(vector<int>& vec) {
    int n = generateRandomNumber(10, 20);
    for (int i = 0; i < n; i++) {
        vec.push_back(generateRandomNumber(1, 100));
    }
}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void countEvenOdd(const vector<int>& vec, int& evenCount, int& oddCount) {
    for (int num : vec) {
        if (num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
}

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void printPrimeNumbers(const vector<int>& vec) {
    cout << "Prime numbers: ";
    for (int num : vec) {
        if (isPrime(num)) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<int> randomIntegers;

    generateRandomIntegers(randomIntegers);
    cout << "Generated integers: ";
    printVector(randomIntegers);

    int evenCount = 0, oddCount = 0;
    countEvenOdd(randomIntegers, evenCount, oddCount);
    cout << "Even numbers count: " << evenCount << endl;
    cout << "Odd numbers count: " << oddCount << endl;

    printPrimeNumbers(randomIntegers);

    return 0;
}
