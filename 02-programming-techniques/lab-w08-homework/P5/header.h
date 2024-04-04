#pragma once

struct Node{
    int data;
    Node* pNext;
};

void insertToSortedList(Node* &pHead, int x);
void inputList(Node *&pHead);
void outputList(Node *pHead);
void deallocateLinkedList(Node* &pHead);
