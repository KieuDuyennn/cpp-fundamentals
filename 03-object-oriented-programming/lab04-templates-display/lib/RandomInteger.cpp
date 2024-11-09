#include "RandomInteger.h"
#include <chrono>
#include <random>

RandomInteger::RandomInteger()
    : generator(std::chrono::system_clock::now().time_since_epoch().count()) {}

int RandomInteger::next() {
    std::uniform_int_distribution<int> distribution(0, 65535);
    return distribution(generator);
}

int RandomInteger::next(int max) {
    std::uniform_int_distribution<int> distribution(0, max - 1);
    return distribution(generator);
}

int RandomInteger::next(int left, int right) {
    std::uniform_int_distribution<int> distribution(left, right);
    return distribution(generator);
}
