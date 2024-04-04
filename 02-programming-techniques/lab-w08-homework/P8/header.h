#pragma once

struct Node{
    int data;
    Node* pNext;
};

void combine2List(Node *&pH1, Node *&pH2, Node *&pN);
void inputList(Node *&pHead);
void outputList(Node *pHead);
void deallocateLinkedList(Node* &pHead);
