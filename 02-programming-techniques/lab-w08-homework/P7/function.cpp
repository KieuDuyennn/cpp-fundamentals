#include <iostream>
#include <fstream>
#include "header.h"


void rearrangeInto2List(Node *&pHead,Node *&p_new_1,Node *&p_new_2)
{
    bool check = 0;

    Node *cur1 = nullptr, *cur2 = nullptr;
    while(pHead != nullptr)
    {
        check = !check;
        if(check){
            if(p_new_1 == nullptr){
                p_new_1 = pHead;
                cur1 = p_new_1;
            } 
            else{
                cur1 -> pNext = pHead;
                cur1 = cur1 -> pNext;
            }     
        }
        else{
            if(p_new_2 == nullptr){
                p_new_2 = pHead;
                cur2 = p_new_2;
            } 
            else{
                cur2 -> pNext = pHead;
                cur2 = cur1 -> pNext;
            }
        }
        pHead = pHead -> pNext;
    }
    if(cur1) cur1 -> pNext = nullptr;
    if(cur2) cur2 -> pNext = nullptr;
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
