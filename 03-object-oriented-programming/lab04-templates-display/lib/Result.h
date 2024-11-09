#ifndef RESULT_H
#define RESULT_H

#include <string>

template <typename T>
class Result {
public:
    bool success;
    int errorCode;
    std::string message;
    T data;

    Result(bool s, int e, const std::string& m, T d)
        : success(s), errorCode(e), message(m), data(d) {}
};

#endif
