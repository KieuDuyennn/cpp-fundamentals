#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
    float X;
    float Y;

    Point(float x = 0.0f, float y = 0.0f);
    void print() const;
};

#endif // POINT_H
