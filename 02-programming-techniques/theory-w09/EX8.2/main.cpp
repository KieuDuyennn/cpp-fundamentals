#include <iostream>


struct SNode {
    int data;
    SNode* next;
};


struct SList {
    SNode* head;
};


int count_nodes(const SList& list) {
    int count = 0;
    SNode* current = list.head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}


void reverse_list(SList& list) {
    SNode* prev = nullptr;
    SNode* current = list.head;
    SNode* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list.head = prev;
}


void add_node(SList& list, int value) {
    SNode* newNode = new SNode;
    newNode->data = value;
    newNode->next = nullptr;

    if (list.head == nullptr) {
        list.head = newNode;
        return;
    }

    SNode* current = list.head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}


void display_list(const SList& list) {
    SNode* current = list.head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


void delete_list(SList& list) {
    SNode* current = list.head;
    while (current != nullptr) {
        SNode* temp = current;
        current = current->next;
        delete temp;
    }
    list.head = nullptr;
}


void display_menu() {
    std::cout << "===== MENU =====\n";
    std::cout << "1. Đếm số nút trong danh sách\n";
    std::cout << "2. Đảo ngược danh sách\n";
    std::cout << "3. Thêm một nút mới vào cuối danh sách\n";
    std::cout << "4. Hiển thị danh sách\n";
    std::cout << "5. Xóa danh sách\n";
    std::cout << "6. Thoát\n";
    std::cout << "================\n";
}

int main() {
    SList my_list;
    my_list.head = nullptr;
    int choice;
    int value;

    do {
        display_menu();
        std::cout << "Nhập lựa chọn của bạn: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Số nút trong danh sách: " << count_nodes(my_list) << std::endl;
                break;
            case 2:
                reverse_list(my_list);
                std::cout << "Danh sách đã được đảo ngược." << std::endl;
                break;
            case 3:
                std::cout << "Nhập giá trị của nút mới: ";
                std::cin >> value;
                add_node(my_list, value);
                std::cout << "Nút mới đã được thêm vào cuối danh sách." << std::endl;
                break;
            case 4:
                std::cout << "Danh sách: ";
                display_list(my_list);
                break;
            case 5:
                delete_list(my_list);
                std::cout << "Danh sách đã được xóa." << std::endl;
                break;
            case 6:
                std::cout << "Chương trình kết thúc." << std::endl;
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
