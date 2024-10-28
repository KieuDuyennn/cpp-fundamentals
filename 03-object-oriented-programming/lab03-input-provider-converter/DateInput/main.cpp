#include <iostream>
#include "DateKeyboardProvider.h"
#include "DateToStringConverter.h"

int main() {
    DateKeyboardProvider provider;
    Date d = provider.next("Enter your birthday (dd/mm/yyyy):");
    
    DateToStringConverter converter;
    std::cout << "You have entered: " << converter.convert(d) << std::endl;

    return 0;
}
