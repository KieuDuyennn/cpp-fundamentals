#include <iostream>
#include <fstream>
#include "header.h"

void inputFromFile(Node* &pHead)
{
    std::ifstream fi("test.txt");
    if (!fi.is_open())
    {
        std::cout << "Error: File not found!";
        return;
    }
    int tmp;
    Node* cur = pHead;
    while (fi >> tmp)
    {
        if (tmp == 0) break;
        Node* newNode = new Node;
        newNode -> data = tmp;
        newNode -> pNext = nullptr;
        if (pHead == nullptr) 
        {
            pHead = newNode;
            cur = pHead;
        }
        else
        {
            cur->pNext = newNode;
            cur = cur->pNext;
        }
    }
    fi.close();
}

void outputToFile(Node* pHead)
{
    std::ofstream fo("output.txt");
    if (!fo.is_open())
    {
        std::cout << "Error: File not found!";
        return;
    }

    Node* cur = pHead;
    while(cur)
    {
        fo << cur -> data << " ";
        cur = cur -> pNext;
    }
    fo.close();
}

void deallocateLinkedList(Node* &pHead)
{
    Node* tmp;
    while(pHead != nullptr)
    {
        tmp = pHead;
        pHead = pHead -> pNext;
        delete tmp;
    }
}

void removeAllX(Node* &pHead, int x)
{
    if(!pHead) return;

    Node* cur = pHead, *tmp;
    while(cur -> pNext)
    {
        while(cur -> pNext && cur -> pNext -> data == x)
        {
            tmp = cur -> pNext;
            cur -> pNext = cur -> pNext -> pNext;
            delete tmp;
        }
        cur = cur -> pNext;
    }

    if(pHead -> data == x)
    {
        tmp = pHead;
        pHead = pHead -> pNext;
        delete tmp;
    }
}
