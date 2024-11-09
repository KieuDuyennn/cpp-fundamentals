#ifndef FRACTIONKEYBOARDPROVIDER_H
#define FRACTIONKEYBOARDPROVIDER_H

#include "../../lib/Result.h"
#include "../../lib/Fraction.h"
#include <string>

class FractionKeyboardProvider {
public:
    Result<Fraction> next();
};

#endif
