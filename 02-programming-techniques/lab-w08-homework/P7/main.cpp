#include <iostream>
#include <fstream>
#include "header.h"

int main()
{
    Node *list = nullptr, *new_list_1 = nullptr, *new_list_2 = nullptr;

    std::cout << "Input list ""in"": ";
    inputList(list);

    rearrangeInto2List(list, new_list_1, new_list_2);

    outputList(new_list_1);
    outputList(new_list_2);

    deallocateLinkedList(new_list_1);
    deallocateLinkedList(new_list_2);
    return 0;
}

/*
    Input1: 1 2 2 6 7 0
    Output1: 1 2 7
             2 6

    Input2: 3 0
    Output2: 3
    
*/
