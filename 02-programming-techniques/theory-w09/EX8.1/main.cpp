#include <iostream>

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

struct DList {
    DNode* head;
    DNode* tail;
};


void initialize_list(DList& list) {
    list.head = nullptr;
    list.tail = nullptr;
}

bool is_empty(const DList& list) {
    return list.head == nullptr;
}


void add_tail(DList& list, int val) {
    DNode* newNode = new DNode;
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = list.tail;

    if (!list.head) {
        list.head = newNode;
    } else {
        list.tail->next = newNode;
    }
    list.tail = newNode;
}


void add_head(DList& list, int val) {
    DNode* newNode = new DNode;
    newNode->data = val;
    newNode->next = list.head;
    newNode->prev = nullptr;

    if (!list.tail) {
        list.tail = newNode;
    } else {
        list.head->prev = newNode;
    }
    list.head = newNode;
}


void add_after_ith_element(DList& list, int i, int val) {
    if (i < 0)
        return;

    DNode* current = list.head;
    int count = 0;
    while (current != nullptr && count < i) {
        current = current->next;
        count++;
    }
    if (current == nullptr) {
        add_tail(list, val); // Nếu không tìm thấy vị trí, thêm vào cuối danh sách
    } else {
        DNode* newNode = new DNode;
        newNode->data = val;
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next)
            current->next->prev = newNode;
        else
            list.tail = newNode; // Nếu thêm vào cuối danh sách
        current->next = newNode;
    }
}


int find_ith_element(const DList& list, int i) {
    DNode* current = list.head;
    int count = 0;
    while (current != nullptr && count < i) {
        current = current->next;
        count++;
    }
    if (current == nullptr) {
        return -1; 
    }
    return current->data;
}


DNode* find_element_with_value(const DList& list, int x) {
    DNode* current = list.head;
    while (current != nullptr) {
        if (current->data == x) {
            return current;
        }
        current = current->next;
    }
    return nullptr; 
}


int find_last_element(const DList& list) {
    if (!list.tail) {
        return -1; 
    }
    return list.tail->data;
}


void remove_head(DList& list) {
    if (!list.head)
        return;

    DNode* temp = list.head;
    list.head = list.head->next;
    if (list.head)
        list.head->prev = nullptr;
    else
        list.tail = nullptr;
    delete temp;
}


void remove_tail(DList& list) {
    if (!list.tail)
        return;

    DNode* temp = list.tail;
    list.tail = list.tail->prev;
    if (list.tail)
        list.tail->next = nullptr;
    else
        list.head = nullptr;
    delete temp;
}


void remove_ith_element(DList& list, int i) {
    if (i < 0)
        return;

    DNode* current = list.head;
    int count = 0;
    while (current != nullptr && count < i) {
        current = current->next;
        count++;
    }
    if (current == nullptr)
        return; 

    if (current->prev)
        current->prev->next = current->next;
    else
        list.head = current->next;
    if (current->next)
        current->next->prev = current->prev;
    else
        list.tail = current->prev;
    delete current;
}


void remove_all(DList& list) {
    while (list.head) {
        remove_head(list);
    }
}


void display_menu() {
    std::cout << "======= Doubly Linked List Operations Menu =======\n";
    std::cout << "1. Add to head\n";
    std::cout << "2. Add to tail\n";
    std::cout << "3. Add after ith element\n";
    std::cout << "4. Find ith element\n";
    std::cout << "5. Find element with value\n";
    std::cout << "6. Find last element\n";
    std::cout << "7. Remove head\n";
    std::cout << "8. Remove tail\n";
    std::cout << "9. Remove ith element\n";
    std::cout << "10. Remove all\n";
    std::cout << "11. Exit\n";
    std::cout << "===================================================\n";
}

int main() {
    DList my_list;
    initialize_list(my_list);
    int choice;
    int val, i;
    while (true) {
        display_menu();
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) break;
        switch (choice) {
            case 1:
                std::cout << "Enter value to add to head: ";
                std::cin >> val;
                add_head(my_list, val);
                break;
            case 2:
                std::cout << "Enter value to add to tail: ";
                std::cin >> val;
                add_tail(my_list, val);
                break;
            case 3:
                std::cout << "Enter position to add after: ";
                std::cin >> i;
                std::cout << "Enter value to add: ";
                std::cin >> val;
                add_after_ith_element(my_list, i, val);
                break;
            case 4:
                std::cout << "Enter index to find: ";
                std::cin >> i;
                std::cout << "Element at index " << i << ": " << find_ith_element(my_list, i) << std::endl;
                break;
            case 5:
                std::cout << "Enter value to find: ";
                std::cin >> val;
                if (find_element_with_value(my_list, val))
                    std::cout << "Element with value " << val << " found." << std::endl;
                else
                    std::cout << "Element with value " << val << " not found." << std::endl;
                break;
            case 6:
                std::cout << "Last element: " << find_last_element(my_list) << std::endl;
                break;
            case 7:
                remove_head(my_list);
                std::cout << "Head removed." << std::endl;
                break;
            case 8:
                remove_tail(my_list);
                std::cout << "Tail removed." << std::endl;
                break;
            case 9:
                std::cout << "Enter index to remove: ";
                std::cin >> i;
                remove_ith_element(my_list, i);
                std::cout << "Element at index " << i << " removed." << std::endl;
                break;
            case 10:
                remove_all(my_list);
                std::cout << "All elements removed." << std::endl;
                break;
            case 11:
                std::cout << "Exiting program." << std::endl;
                remove_all(my_list);
                return 0;
            default:
                std::cout << "Invalid choice! Please enter a valid option." << std::endl;
        }
    }
    remove_all(my_list);
    return 0;
}

