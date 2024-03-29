#include "function.h" 
SNode* makeNode(int data, SNode* next) {
    SNode* newNode = new SNode;
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

void insertAfter(SNode* prevNode, int value) {
    if (prevNode == nullptr)
        return;
    SNode* newNode = makeNode(value, prevNode->next);
    prevNode->next = newNode;
}



void loadFromFile(const std::string& filename, SList& list) {
   std::ifstream file(filename);
    int num;
    while (file >> num) {
        insertAfter(list.head, num);
        if (list.head == nullptr)
            list.head = makeNode(num, nullptr);
            }
    file.close();
}


void deleteValue(SList& list, int x) {
    SNode* current = list.head;
    SNode* prev = nullptr;

    while (current != nullptr) {
        if (current->data == x) {
            if (prev == nullptr) {
                list.head = current->next;
                delete current;
                current = list.head;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}


void printToFile(const std::string& filename, const SList& list) {
    std::ofstream file(filename);
    SNode* current = list.head;
    while (current != nullptr) {
        file << current->data << " ";
        current = current->next;
    }
    file.close();
}


void printList(const SList& list) {
    SNode* current = list.head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
