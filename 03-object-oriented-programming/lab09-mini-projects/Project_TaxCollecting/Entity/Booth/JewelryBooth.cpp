#include "JewelryBooth.h"

JewelryBooth::JewelryBooth(std::string id, int area, int securityFee)
    : _id(id), _area(area), _securityFee(securityFee) {}

std::string JewelryBooth::getId() {
    return _id;
}

std::string JewelryBooth::getType() {
    return "Da qui";
}

int JewelryBooth::getArea() {
    return _area;
}

int JewelryBooth::calculateBaseRent() {
    return _area * 560000;
}

int JewelryBooth::calculateAdditionalFee() {
    return _securityFee;
}

int JewelryBooth::calculateTotalRent() {
    return calculateBaseRent() + calculateAdditionalFee();
}

std::string JewelryBooth::toString() {
    return "JewelryBooth";
}
