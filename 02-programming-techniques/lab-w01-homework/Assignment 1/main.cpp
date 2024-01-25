#include "Function.h"
int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    Date dates[1000]; 
    int n = 0; 

    inputDates(dates, n, inputFile);

    std::sort(dates, dates + n, compareDates);

    outputDates(dates, n, outputFile);
   
   return 0; 
} 
