#pragma once

struct Node{
    int data;
    Node* pNext;
};

void reverseList(Node* &pHead);
void inputFromFile(Node* &pHead);
void outputToFile(Node* pHead);
void deallocateLinkedList(Node* &pHead);
