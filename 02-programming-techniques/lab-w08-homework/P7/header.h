#pragma once

struct Node{
    int data;
    Node* pNext;
};

void rearrangeInto2List(Node *&pHead,Node *&p_new_1,Node *&p_new_2);
void inputList(Node *&pHead);
void outputList(Node *pHead);
void deallocateLinkedList(Node* &pHead);
