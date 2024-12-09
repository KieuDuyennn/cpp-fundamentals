#include "SecurityFee.h"

SecurityFee::SecurityFee(int fee) : _fee(fee) {}

int SecurityFee::calculateFee() {
    return _fee;
}

std::string SecurityFee::toString() {
    return "SecurityFee";
}
