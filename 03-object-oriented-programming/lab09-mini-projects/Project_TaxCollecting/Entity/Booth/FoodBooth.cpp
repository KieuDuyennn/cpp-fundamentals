#include "FoodBooth.h"

FoodBooth::FoodBooth(std::string id, int area, int coldStorageFee)
    : _id(id), _area(area), _coldStorageFee(coldStorageFee) {}

std::string FoodBooth::getId() {
    return _id;
}

std::string FoodBooth::getType() {
    return "Thuc pham";
}

int FoodBooth::getArea() {
    return _area;
}

int FoodBooth::calculateBaseRent() {
    return _area * 560000;
}

int FoodBooth::calculateAdditionalFee() {
    return _coldStorageFee;
}

int FoodBooth::calculateTotalRent() {
    return calculateBaseRent() + calculateAdditionalFee();
}

std::string FoodBooth::toString() {
    return "FoodBooth";
}
