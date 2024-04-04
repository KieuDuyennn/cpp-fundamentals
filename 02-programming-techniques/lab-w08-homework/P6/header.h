#pragma once

struct Node{
    int data;
    Node* pNext;
};

void createNewList(Node* in, Node* &out);
void inputList(Node *&pHead);
void outputList(Node *pHead);
void deallocateLinkedList(Node* &pHead);
