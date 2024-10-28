#ifndef LINE_H
#define LINE_H

#include <string>

class Line {
private:
    std::string _startX, _startY;  // Store as strings
    std::string _endX, _endY;

public:
    Line() {}

    void setStart(const std::string& x, const std::string& y) {
        _startX = x;
        _startY = y;
    }

    void setEnd(const std::string& x, const std::string& y) {
        _endX = x;
        _endY = y;
    }

    std::string getStartX() { return _startX; }
    std::string getStartY() { return _startY; }
    std::string getEndX() { return _endX; }
    std::string getEndY() { return _endY; }
};

#endif // LINE_H
