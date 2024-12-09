#include "Integer.h"

Integer::Integer() : _value(0) {}

Integer::Integer(int value) : _value(value) {}

int Integer::value() {
    return _value;
}

std::string Integer::toString() {
    return std::to_string(_value);
}
