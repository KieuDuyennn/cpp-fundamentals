#include <iostream>
#include <algorithm>
#include <fstream>
#pragma once

struct Date {
    int year, month, day;
};
bool compareDates(const Date& a, const Date& b);
void inputDates(Date dates[], int &n, std::ifstream &inputFile);
void outputDates(const Date dates[], int n, std::ofstream &outputFile);
