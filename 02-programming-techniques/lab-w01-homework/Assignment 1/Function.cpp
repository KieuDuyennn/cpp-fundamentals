#include "Function.h" 
bool compareDates(const Date& a, const Date& b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

void inputDates(Date dates[], int &n, std::ifstream &inputFile) {
    int year, month, day;
    while (inputFile >> year >> month >> day && year != -1 && month != -1 && day != -1) {
        dates[n++] = {year, month, day};
    }
}

void outputDates(const Date dates[], int n, std::ofstream &outputFile) {
    for(int i = 0; i < n; i++){
       outputFile << dates[i].year << ' ' << dates[i].month << ' ' << dates[i].day << '\n';
    }
}

