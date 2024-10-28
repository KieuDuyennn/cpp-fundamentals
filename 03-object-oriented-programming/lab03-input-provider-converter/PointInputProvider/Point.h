#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
private:
    std::string _x;  // Store x as string
    std::string _y;  // Store y as string

public:
    Point() : _x("0.0"), _y("0.0") {}  // Default constructor

    void set(const std::string& x, const std::string& y) {
        _x = x;
        _y = y;
    }

    std::string getX() { return _x; }
    std::string getY() { return _y; }
};

#endif // POINT_H
