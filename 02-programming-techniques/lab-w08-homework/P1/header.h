#pragma once

struct Node{
    int data;
    Node *pNext;
};

void inputFromFile(Node* &pHead);
void outputToFile(Node* pHead);
void deallocateLinkedList(Node* &pHead);
void removeAllX(Node* &pHead, int x);
