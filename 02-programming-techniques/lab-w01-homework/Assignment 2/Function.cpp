#include "Function.h"

void loadStudents(std::ifstream& input, Student students[], int& size) {
    int id;
    std::string fullName;
    float gpa;

    while (input >> id >> fullName >> gpa) {
        students[size++] = Student(id, fullName, gpa);
    }
}

void saveHonors(std::ofstream& output, Student students[], int size) {
    for (int i = 0; i < size; ++i) {
        output << students[i].id << " " << students[i].fullName << " " << students[i].gpa << std::endl;
    }
}

void sortStudents(Student students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (students[i].gpa < students[j].gpa) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
