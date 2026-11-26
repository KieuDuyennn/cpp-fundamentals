#ifndef FUNCTION_H
#define FUNCTION_H

#include <fstream>
#include <string>

struct Student {
    int id = 0;
    std::string fullName;
    float gpa = 0.0f;

    Student() = default;
    Student(int id, const std::string& fullName, float gpa)
        : id(id), fullName(fullName), gpa(gpa) {}
};

// Reads "id name gpa" lines until the file ends or capacity is reached.
void loadStudents(std::ifstream& input, Student students[], int& size, int capacity);
void saveHonors(std::ofstream& output, const Student students[], int size);
void sortStudents(Student students[], int size);

#endif
