#include "app/RentService.h"

int main() {
    RentService rentService;
    rentService.processRentData("resources/RentMay24.txt", "resources/RentReport.txt");
    return 0;
}
