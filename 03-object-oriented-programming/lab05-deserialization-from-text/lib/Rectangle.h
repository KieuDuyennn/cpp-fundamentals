#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

class Rectangle {
private:
    int _width;
    int _height;

public:
    Rectangle(int width, int height);
    int getWidth() const;
    int getHeight() const;
    std::string toString() const;
};

#endif 
