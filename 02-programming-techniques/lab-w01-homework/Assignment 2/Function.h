#include <string>
#include <fstream>
#include <iostream>

class Student {

    int id;
    std::string fullName;
    float gpa;

    Student(int id, const std::string& fullName, float gpa)
        : id(id), fullName(fullName), gpa(gpa) {}
};

void loadStudents(std::ifstream& input, Student students[], int& size);
void saveHonors(std::ofstream& output, Student students[], int size);
void sortStudents(Student students[], int size);
