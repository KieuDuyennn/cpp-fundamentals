#ifndef MOCKDATAPROVIDER_H
#define MOCKDATAPROVIDER_H

#include <vector>
#include "../../lib/Student.h"

class MockDataProvider {
public:
    std::vector<Student> getAllStudents();
};

#endif 
