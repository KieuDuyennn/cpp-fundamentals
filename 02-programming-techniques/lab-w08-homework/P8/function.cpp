#include <iostream>
#include <fstream>
#include "header.h"


void combine2List(Node *&pH1, Node *&pH2, Node *&pHN)
{
    bool check = 0;

    if(pH2 == nullptr) {
        pHN = pH1;
        pH1 = nullptr;
        return;
    }

    if(pH1 == nullptr) {
        pHN = pH2;
        pH2 = nullptr;
        return;
    }


    Node *tail = nullptr;
    while(pH1 != nullptr && pH2 != nullptr)
    {
        check = !check;
        if(check)
        {
            if(pHN == nullptr){
                pHN = pH1;
                tail = pHN;
            }
            else{
                tail -> pNext = pH1;
                tail = tail -> pNext;
            }
            pH1 = pH1 -> pNext;
        }
        else
        {
            tail -> pNext = pH2;
            tail = tail -> pNext;
            pH2 = pH2 -> pNext;
        }
    }
    if(pH1 == nullptr) tail -> pNext = pH2;
    if(pH2 == nullptr) tail -> pNext = pH1;

    pH1 = nullptr;
    pH2 = nullptr;
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
    std::cout << "\n";
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
