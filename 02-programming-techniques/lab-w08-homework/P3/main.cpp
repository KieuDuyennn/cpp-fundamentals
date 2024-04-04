#include <iostream>
#include <fstream>
#include "header.h"

int main()
{
    Node *List = nullptr;

    inputFromFile(List);
    reverseList(List);
    outputToFile(List);
    deallocateLinkedList(List);
    return 0;
}

/*
    Input1: 1 2 3 1 2 0
    Output1: 2 1 3 2 1
*/
