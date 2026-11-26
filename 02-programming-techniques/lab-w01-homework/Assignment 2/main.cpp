#include "Function.h"
#include <iostream>

const int MAX_STUDENTS = 1000;

int main() {
    Student students[MAX_STUDENTS];
    int size = 0;

    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Cannot open input.txt\n";
        return 1;
    }
    loadStudents(input, students, size, MAX_STUDENTS);

    sortStudents(students, size);

    std::ofstream output("honors.txt");
    saveHonors(output, students, size);
    return 0;
}
