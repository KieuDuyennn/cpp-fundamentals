#include <iostream>
#include <string>

void parseFilePath(const std::string& path) {
    size_t lastSlash = path.find_last_of("\\/");
    size_t lastDot = path.find_last_of('.');

    std::string folder = (lastSlash != std::string::npos) ? path.substr(0, lastSlash) : "";
    std::string filename = (lastSlash != std::string::npos) ? path.substr(lastSlash + 1) : path;
    std::string extension = (lastDot != std::string::npos && lastDot > lastSlash) ? path.substr(lastDot + 1) : "";

    std::cout << "Folder: " << folder << std::endl;
    std::cout << "Filename: " << filename << std::endl;
    std::cout << "Extension: " << extension << std::endl;
}

int main() {
    std::string path;
    std::cout << "Enter a file path: ";
    std::getline(std::cin, path);
    parseFilePath(path);
    return 0;
}
