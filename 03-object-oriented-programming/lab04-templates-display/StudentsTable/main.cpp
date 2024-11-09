#include <iostream>
#include "bus/MockDataProvider.h"
#include "ui/StudentsToTableConverter.h"
#include "../lib/Student.h" 

int main() {
    MockDataProvider provider;
    std::vector<Student> students = provider.getAllStudents();

    std::vector<std::string> headers = { "STT", "MSSV", "Ho va ten", "Email" };
    std::vector<int> columnSizes = {3, 4, 20, 20};
    StudentsToTableConverter table(headers, columnSizes);

    std::string info = table.convert(students);
    std::cout << info;

    return 0;
}
