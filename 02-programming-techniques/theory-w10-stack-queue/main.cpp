#include <iostream>
#include <string>

struct Student {
    std::string name;
    int points;
};

struct SNode {
    Student data;
    SNode* next;
};

struct Stack {
    SNode* top;
};

void cinStu(Student &s) {
    std::cin.ignore(); 
    std::cout << "Enter name of student: ";
    getline(std::cin, s.name);
    std::cout << "Enter points of student: ";
    std::cin >> s.points;
}

void pushStu(Stack &s) {
    SNode* newNode = new SNode;
    Student newStudent;
    cinStu(newStudent);
    newNode->data = newStudent;
    newNode->next = s.top;
    s.top = newNode;
}

SNode* popStu(Stack &s) {
    if (s.top == nullptr) {
        std::cerr << "Stack is empty.\n";
        return nullptr;
    }
    SNode* topNode = s.top;
    s.top = s.top->next;
    return topNode;
}

bool isEmpty(const Stack &s) {
    return s.top == nullptr;
}
// Pops up to N students. The stack is passed by reference so the caller sees the change.
void remove_N_Students(int N, Stack &s){
    for (int i = 1; i <= N && !isEmpty(s); i++) delete popStu(s);
}
void displayStudents(const Stack &s) {
    if (isEmpty(s)) {
        std::cout << "Stack is empty.\n";
        return;
    }
    std::cout << "Students in the stack:\n";
    SNode* current = s.top;
    while (current != nullptr) {
        std::cout << "Name: " << current->data.name << ", Points: " << current->data.points << std::endl;
        current = current->next;
    }
}

float averagePoints(const Stack &s) {
    if (isEmpty(s)) {
        std::cerr << "Stack is empty.\n";
        return 0;
    }
    float totalPoints = 0;
    int count = 0;
    SNode* current = s.top;
    while (current != nullptr) {
        totalPoints += current->data.points;
        count++;
        current = current->next;
    }
    return totalPoints / count;
}

int searchPoints(const Stack &s, const std::string& name) {
    if (isEmpty(s)) {
        std::cerr << "Stack is empty.\n";
        return -1;
    }
    SNode* current = s.top;
    while (current != nullptr) {
        if (current->data.name == name) {
            return current->data.points;
        }
        current = current->next;
    }
    std::cerr << "Student '" << name << "' not found.\n";
    return -1;
}
void clearStack(Stack &s){
    while (s.top != NULL){
        SNode * tmp=s.top;
        s.top=s.top->next;
        delete tmp;
    }
 }
int main() {
    Stack studentStack;
    studentStack.top = nullptr;
    int n;
    std::cout<<  "Enter number of students";
    std::cin>>n;
    std::cout << "Adding students:\n";
    for (int i=1;i<=n;i++)
         pushStu(studentStack);
    std::cout << "\nDisplaying all students:\n";
    displayStudents(studentStack);
    

    std::cout << "\nRemoving one student:\n";
    SNode* removedStudent = popStu(studentStack);
    if (removedStudent != nullptr) {
        std::cout << "Removed student: " << removedStudent->data.name << std::endl;
        delete removedStudent;
    }


    std::cout << "\nDisplaying all students after removing one:\n";
    displayStudents(studentStack);

   
    std::cout << "\nAverage points of all students: " << averagePoints(studentStack) << std::endl;

   
    std::cout << "\nSearch for a student's points:\n";
    std::string searchName;
    std::cout << "Enter name of student to search: ";
    std::cin >> searchName;
    int searchResult = searchPoints(studentStack, searchName);
    if (searchResult != -1) {
        std::cout << "Points of student '" << searchName << "': " << searchResult << std::endl;
    }

    clearStack(studentStack);
    return 0;
}
