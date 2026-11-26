#include <iostream>
#include <fstream>
#include "header.h"

void insertToSortedList(Node* &pHead, int x)
{
    Node *new_node = new Node;
    new_node -> data = x;
    new_node -> pNext = pHead;

    if(pHead == nullptr || pHead -> data > x) 
    {
        pHead = new_node;
        return;
    }

    Node *cur = pHead;
    while(cur -> pNext != nullptr && cur -> pNext -> data < x)
        cur = cur -> pNext;
    new_node -> pNext = cur -> pNext;
    cur -> pNext = new_node;
}

void inputList(Node *&pHead)
{
    int tmp;
    Node* tail = pHead;
    while (tail != nullptr && tail->pNext != nullptr) tail = tail->pNext;
    while (std::cin >> tmp)
    {
        if(tmp == 0) break;
        Node* newNode = new Node;
        newNode -> data = tmp;
        newNode -> pNext = nullptr;
        if (pHead == nullptr) pHead = newNode;
        else tail->pNext = newNode;
        tail = newNode;
    }
}

void outputList(Node *pHead)
{
    Node* cur = pHead;
    while(cur)
    {
        std::cout << cur -> data << " ";
        cur = cur -> pNext;
    }
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
