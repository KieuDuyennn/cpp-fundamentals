#include <iostream>
#include <fstream>
#include "header.h"

void createNewList(Node* in, Node* &out)
{
    if(in == nullptr) return;

    int value = 0;
    Node* cur = nullptr;

    while(in != nullptr)
    {
        value += in -> data;
        if(out == nullptr)
        {
            out = new Node;
            out -> data = value;
            out -> pNext = nullptr;
            cur = out;
        }
        else
        {
            cur -> pNext = new Node;

            cur = cur -> pNext;
            cur -> data = value;
            cur -> pNext = nullptr;
        }
        in = in -> pNext;
    }
}

void inputList(Node *&pHead)
{
    int tmp;
    Node* cur = pHead;
    while (std::cin >> tmp)
    {
        if(tmp == 0) break;
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
            cur -> pNext = newNode;
            cur = cur -> pNext;
        }
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
