#include <iostream>
#include <fstream>
#include "header.h"

int main()
{
    Node *list_1 = nullptr, *list_2 = nullptr, *new_list = nullptr;

    std::cout << "Input list 1: ";
    inputList(list_1);

    std::cout << "Input list 2: ";
    inputList(list_2);

    combine2List(list_1, list_2, new_list);

    outputList(new_list);

    deallocateLinkedList(new_list);
    return 0;
}

/*
    Input1: 1 2 3
            1 2
    Output1: 1 1 2 2 3

    Input2: 3 0
            0
    Output2: 3

    Inpur3: 0
            1 0
    Output3: 1

*/
