#ifndef RANDOMINTEGER_H
#define RANDOMINTEGER_H

#include <random>

class RandomInteger {
public:
    RandomInteger();
    int next();
    int next(int max);
    int next(int left, int right);

private:
    std::mt19937 generator;
};

#endif
