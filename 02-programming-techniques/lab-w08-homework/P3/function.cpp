#include <iostream>
#include <fstream>
#include "header.h"

void reverseList(Node* &pHead)
{
    if(pHead == nullptr) return;
    Node *cur = pHead, *prev = nullptr;
    Node *tmp;
    while(cur -> pNext != nullptr)
    {
        tmp = cur;
        cur = cur -> pNext;
        tmp -> pNext = prev;
        prev = tmp;
    } 
    cur -> pNext = prev;
    pHead = cur;
}

void inputFromFile(Node* &pHead)
{
    std::ifstream fi("test.txt");
    if (!fi.is_open())
    {
        std::cout << "Error: File not found!";
        return;
    }
    int tmp;
    Node* tail = pHead;
    while (tail != nullptr && tail->pNext != nullptr) tail = tail->pNext;
    while (fi >> tmp)
    {
        if(tmp == 0) break;
        Node* newNode = new Node;
        newNode -> data = tmp;
        newNode -> pNext = nullptr;
        if (pHead == nullptr) pHead = newNode;
        else tail->pNext = newNode;
        tail = newNode;
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
