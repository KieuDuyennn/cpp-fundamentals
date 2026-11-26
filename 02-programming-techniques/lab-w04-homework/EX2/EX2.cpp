#include <iostream>
#include <fstream>
#include <algorithm>

struct Date {
    int day;
    int month;
    int year;
};

void enterDates(Date* dates, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhập ngày thứ " << i + 1 << " (dd mm yyyy): ";
        std::cin >> dates[i].day >> dates[i].month >> dates[i].year;
    }
}

void saveDates(const Date* dates, int n, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << n << "\n";
        for (int i = 0; i < n; ++i) {
            file << dates[i].day << " " << dates[i].month << " " << dates[i].year << "\n";
        }
    }
}

Date loadDatesAndFindNewest(const std::string& filename) {
    std::ifstream file(filename);
    Date newestDate = { 0, 0, 0 };
    if (file.is_open()) {
        int n;
        file >> n;
        Date* dates = new Date[n];
        for (int i = 0; i < n; ++i) {
            file >> dates[i].day >> dates[i].month >> dates[i].year;
            if (dates[i].year > newestDate.year ||
                (dates[i].year == newestDate.year && dates[i].month > newestDate.month) ||
                (dates[i].year == newestDate.year && dates[i].month == newestDate.month && dates[i].day > newestDate.day)) {
                newestDate = dates[i];
            }
        }
        delete[] dates;
    }
    return newestDate;
}

void printMenu() {
    std::cout << "1. Nhập mảng ngày từ bàn phím và lưu vào tệp\n";
    std::cout << "2. Tải mảng ngày từ tệp và tìm ngày mới nhất\n";
    std::cout << "3. Thoát\n";
    std::cout << "Chọn một lựa chọn: ";
}

int main() {
    int choice;
    do {
        printMenu();
        if (!(std::cin >> choice)) break;
        switch (choice) {
        case 1: {
            int n;
            std::cout << "Nhập số lượng ngày: ";
            std::cin >> n;
            Date* dates = new Date[n];
            enterDates(dates, n);
            saveDates(dates, n, "input.txt");
            delete[] dates;
            break;
        }
        case 2: {
            Date newestDate = loadDatesAndFindNewest("input.txt");
            std::cout << "Ngày mới nhất: " << newestDate.day << "/" << newestDate.month << "/" << newestDate.year << "\n";
            break;
        }
        case 3:
            std::cout << "Thoát chương trình.\n";
            break;
        default:
            std::cout << "Lựa chọn không hợp lệ. \n";
        }
    } while (choice != 3);
    return 0;
}
