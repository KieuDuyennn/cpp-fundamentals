#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct SNode {
    int data;
    SNode* next;
};

struct SList {
    SNode* head;
};
SNode* makeNode(int data, SNode* next);
void insertAfter(SNode* prevNode, int value);
void loadFromFile(const std::string& filename, SList& list);
void deleteValue(SList& list, int x);
void printToFile(const std::string& filename, const SList& list) ;
void printList(const SList& list);
