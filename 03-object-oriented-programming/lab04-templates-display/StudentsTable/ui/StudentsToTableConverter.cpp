#include "StudentsToTableConverter.h"
#include <iomanip>
#include <sstream>

StudentsToTableConverter::StudentsToTableConverter(const std::vector<std::string>& headers, const std::vector<int>& columnSizes)
    : _headers(headers), _columnSizes(columnSizes) {}

std::string StudentsToTableConverter::convert(const std::vector<Student>& students) const {
    std::ostringstream oss;
    oss << formatRow(_headers) << "\n";

    int separatorLength = 0;
    for (size_t i = 0; i < _columnSizes.size(); ++i) {
        separatorLength += _columnSizes[i];
    }
    separatorLength += _columnSizes.size() - 1;

    oss << std::string(separatorLength, '-') << "\n";

    StudentToRowConverter rowConverter(_columnSizes);
    for (size_t i = 0; i < students.size(); ++i) {
        oss << rowConverter.convert(students[i], i + 1) << "\n";
    }

    return oss.str();
}

std::string StudentsToTableConverter::formatRow(const std::vector<std::string>& rowValues) const {
    std::ostringstream oss;
    for (size_t i = 0; i < rowValues.size(); ++i) {
        oss << "|" << std::setw(_columnSizes[i]) << std::left << rowValues[i];
    }
    oss << "|";
    return oss.str();
}

StudentsToTableConverter::StudentToRowConverter::StudentToRowConverter(const std::vector<int>& columnSizes)
    : _columnSizes(columnSizes) {}

std::string StudentsToTableConverter::StudentToRowConverter::convert(const Student& student, int index) const {
    std::vector<std::string> rowValues = {
        std::to_string(index),
        student._id,
        student._fullname,
        student._email
    };
    std::ostringstream oss;
    for (size_t i = 0; i < rowValues.size(); ++i) {
        oss << "|" << std::setw(_columnSizes[i]) << std::left << rowValues[i];
    }
    oss << "|";
    return oss.str();
}
