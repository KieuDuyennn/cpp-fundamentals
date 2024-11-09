#ifndef STUDENTSTOTABLECONVERTER_H
#define STUDENTSTOTABLECONVERTER_H

#include <vector>
#include <string>
#include "../../lib/Student.h"

class StudentsToTableConverter {
private:
    std::vector<std::string> _headers;
    std::vector<int> _columnSizes;

public:
    StudentsToTableConverter(const std::vector<std::string>& headers, const std::vector<int>& columnSizes);
    std::string convert(const std::vector<Student>& students) const;

private:
    std::string formatRow(const std::vector<std::string>& rowValues) const;

    class StudentToRowConverter {
    private:
        std::vector<int> _columnSizes;

    public:
        StudentToRowConverter(const std::vector<int>& columnSizes);
        std::string convert(const Student& student, int index) const;
    };
};

#endif 
