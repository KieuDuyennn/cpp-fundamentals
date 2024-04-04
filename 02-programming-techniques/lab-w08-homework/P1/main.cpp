#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

int main()
{
    Node *a = nullptr;

    inputFromFile(a);

    int x;
    std::cout << "Input x: ";
    std::cin >> x;

    removeAllX(a, x);

    outputToFile(a);

    deallocateLinkedList(a);

    return 0;
}
