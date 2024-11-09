#include "MockDataProvider.h"

std::vector<Student> MockDataProvider::getAllStudents() {
    return {
        Student("001", "Nguyen Van Minh", "nvminh@gmail.com"),
        Student("002", "Cao Ha Thang", "chthang@gmail.com"),
        Student("003", "Tran Duc Tri", "tdtri@gmail.com")
    };
}
