#include "function.h"

#define MAX_STUDENTS 1000

int main() {
    Student students[MAX_STUDENTS];
    int size = 0;

    std::ifstream input("input.txt");
    loadStudents(input, students, size);
    input.close();

    sortStudents(students, size);

    std::ofstream output("honors.txt");
    saveHonors(output, students, size);
    output.close();

    return 0;
}
