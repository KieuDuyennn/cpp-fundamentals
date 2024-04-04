#include <iostream>
#include <fstream>
#include "header.h"

int main()
{
    Node *List = nullptr;
    int x;

    std::cout << "Input x:";
    std::cin >> x;

    std::cout << "Input a sorted list: ";
    inputList(List);

    insertToSortedList(List, x);

    outputList(List);

    deallocateLinkedList(List);
    return 0;
}

/*
    Input1: 1
            2 3 5 0
    Output1: 1 2 3 5

    Input2: 3
            1 2 5 6 0
    Output2: 1 2 3 5 6
*/
