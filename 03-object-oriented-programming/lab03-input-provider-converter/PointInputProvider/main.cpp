#include <iostream>
#include "PointKeyboardProvider.h"
#include "PointToStringConverter.h"

int main() {
    PointKeyboardProvider provider;
    Point p = provider.next("Enter a point.");
    
    PointToStringConverter converter;
    std::cout << "You have entered: " << converter.convert(p) << std::endl;

    return 0;
}
