#include "ColdStorageFee.h"

ColdStorageFee::ColdStorageFee(int fee) : _fee(fee) {}

int ColdStorageFee::calculateFee() {
    return _fee;
}

std::string ColdStorageFee::toString() {
    return "ColdStorageFee";
}
