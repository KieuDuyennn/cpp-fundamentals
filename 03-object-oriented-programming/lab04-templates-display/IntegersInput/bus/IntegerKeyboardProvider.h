#ifndef INTEGERKEYBOARDPROVIDER_H
#define INTEGERKEYBOARDPROVIDER_H

#include "../../lib/Result.h"
#include <string>

class IntegerKeyboardProvider {
public:
    Result<int> next();
    Result<int> next(int min, int max);
};

#endif
