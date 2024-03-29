


#include "function.h"
int main() {
    SList myList = {nullptr};
    std::string filename = "input.txt";

    // Load integers from file into singly linked list
    loadFromFile(filename, myList);

    // Print the loaded list
    std::cout << "List loaded from file: ";
    printList(myList);

    // Ask user for the value x to delete
    int x;
    std::cout << "Enter the value to delete: ";
    std::cin >> x;

    // Delete nodes with value x from the list if x exists
    deleteValue(myList, x);

    // Print the modified list
    std::cout << "List after deleting " << x << ": ";
    printList(myList);

    // Print the modified list to a file
    std::string outputFilename = "output.txt";
    printToFile(outputFilename, myList);
    std::cout << "Modified list saved to " << outputFilename << std::endl;

    return 0;
}
