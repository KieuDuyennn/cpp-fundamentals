#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>

void log(const std::string& message) {
    // Get the current date
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&now_c);
    
    // Format date as yymmdd
    std::ostringstream dateStream;
    dateStream << std::put_time(local_time, "log-%y%m%d.txt");
    std::string filename = dateStream.str();

    // Open the log file in append mode
    std::ofstream logFile;
    logFile.open(filename, std::ios_base::app);

    // Check if the file is opened successfully
    if (logFile.is_open()) {
        logFile << message << std::endl; // Append the message
        logFile.close(); // Close the file
    } else {
        std::cerr << "Error opening log file." << std::endl;
    }
}

int main() {
    log("Exception tại hàm export. Lí do: Invalid input exception");
    return 0;
}
