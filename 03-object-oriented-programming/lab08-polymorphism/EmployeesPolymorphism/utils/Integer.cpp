#include "Integer.h"

Integer::Integer() : _value(0) {}

Integer::Integer(int value) : _value(value) {}

int Integer::value() const {
    return _value;
}

std::string Integer::toString() const {
    return "Integer";
}
