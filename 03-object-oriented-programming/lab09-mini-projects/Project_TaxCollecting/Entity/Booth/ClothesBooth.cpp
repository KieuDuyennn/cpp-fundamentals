#include "ClothesBooth.h"

ClothesBooth::ClothesBooth(std::string id, int area)
    : _id(id), _area(area) {}

std::string ClothesBooth::getId() {
    return _id;
}

std::string ClothesBooth::getType() {
    return "Quan ao";
}

int ClothesBooth::getArea() {
    return _area;
}

int ClothesBooth::calculateBaseRent() {
    return _area * 560000;
}

int ClothesBooth::calculateAdditionalFee() {
    return 0;
}

int ClothesBooth::calculateTotalRent() {
    return calculateBaseRent();
}

std::string ClothesBooth::toString() {
    return "ClothesBooth";
}
