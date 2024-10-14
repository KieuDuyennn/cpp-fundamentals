#include "main.h"

void printDateFormat() {
    // Get the current time
    time_t now = time(0);
    tm* currentTime = localtime(&now);
    
   
    int day = currentTime->tm_mday;
    int month = currentTime->tm_mon + 1; 
    int year = currentTime->tm_year + 1900; 

    // print VN format
    cout << setfill('0') << setw(2) << day << "/"
         << setfill('0') << setw(2) << month << "/"
         << year << endl;

    // Calculate the next date
    tm nextTime = *currentTime;
    nextTime.tm_mday += 1; // Increment the day

    // Normalize the tm structure
    mktime(&nextTime);

    // Extract day, month, and year for the next date
    int nextDay = nextTime.tm_mday;
    int nextMonth = nextTime.tm_mon + 1;
    int nextYear = nextTime.tm_year % 100; // Last two digits of the year

    // Print next date in MM/dd/yy format (US format)
    cout << setfill('0') << setw(2) << nextMonth << "/"
         << setfill('0') << setw(2) << nextDay << "/"
         << nextYear << endl;
}

int main() {
    printDateFormat();
    return 0;
}
