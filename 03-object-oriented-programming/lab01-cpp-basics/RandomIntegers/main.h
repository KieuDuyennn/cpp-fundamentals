#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber(int min, int max);
void generateRandomIntegers(std::vector<int>& vec);
void printVector(const std::vector<int>& vec);
void countEvenOdd(const std::vector<int>& vec, int& evenCount, int& oddCount);
bool isPrime(int number);
void printPrimeNumbers(const std::vector<int>& vec);


