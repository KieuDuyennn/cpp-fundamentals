#ifndef LINE_H
#define LINE_H

class Line {
public:
    float X1;
    float Y1;
    float X2;
    float Y2;

    Line(float x1 = 0.0f, float y1 = 0.0f, float x2 = 0.0f, float y2 = 0.0f);
    void print() const;
};

#endif // LINE_H
