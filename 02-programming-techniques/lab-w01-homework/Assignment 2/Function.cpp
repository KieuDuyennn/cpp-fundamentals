#include "Function.h"
#include <utility>

void loadStudents(std::ifstream& input, Student students[], int& size, int capacity) {
    int id;
    std::string fullName;
    float gpa;

    while (size < capacity && input >> id >> fullName >> gpa) {
        students[size++] = Student(id, fullName, gpa);
    }
}

void saveHonors(std::ofstream& output, const Student students[], int size) {
    for (int i = 0; i < size; ++i) {
        output << students[i].id << " " << students[i].fullName << " " << students[i].gpa << '\n';
    }
}

// Sorts by GPA, highest first.
void sortStudents(Student students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (students[i].gpa < students[j].gpa) {
                std::swap(students[i], students[j]);
            }
        }
    }
}
