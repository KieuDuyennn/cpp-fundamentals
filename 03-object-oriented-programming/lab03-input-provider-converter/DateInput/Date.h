#ifndef DATE_H
#define DATE_H

class Date {
private:
    int _day;
    int _month;
    int _year;

public:
    Date(int day = 0, int month = 0, int year = 0) : _day(day), _month(month), _year(year) {}

    int getDay() const { return _day; }
    int getMonth() const { return _month; }
    int getYear() const { return _year; }

    void setDate(int day, int month, int year) {
        _day = day;
        _month = month;
        _year = year;
    }
};

#endif // DATE_H
