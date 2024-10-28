#include <iostream>
#include "LineKeyboardProvider.h"
#include "LineToStringConverter.h"

int main() {
    LineKeyboardProvider provider;
    Line l = provider.next("Enter a line.");
    
    LineToStringConverter converter;
    std::cout << "You have entered: " << converter.convert(l) << std::endl;

    return 0;
}
