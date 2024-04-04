#include <iostream>
#include <fstream>
#include "header.h"

int main()
{
    Node *in = nullptr, *out = nullptr;

    std::cout << "Input list ""in"": ";
    inputList(in);

    createNewList(in, out);

    outputList(out);

    deallocateLinkedList(in);
    deallocateLinkedList(out);
    return 0;
}

/*
    Input1: 1 2 2 6 7 0
    Output1: 1 3 5 11 18 

    Input2: 3 0
    Output2: 3
*/
