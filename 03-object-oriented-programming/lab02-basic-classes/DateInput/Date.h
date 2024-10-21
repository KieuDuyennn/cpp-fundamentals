#ifndef DATE_H
#define DATE_H

class Date {
public:
    int Day;
    int Month;
    int Year;

    Date(int day = 1, int month = 1, int year = 2000);
    void print() const;
};

#endif // DATE_H
