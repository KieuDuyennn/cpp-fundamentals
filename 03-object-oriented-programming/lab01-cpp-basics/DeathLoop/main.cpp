#include "main.h"

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isValidInteger(const string& input, int& num) {
    if (input.empty()) return false;
    for (char c : input) {
        if (!isDigit(c)) return false;
    }
    
    num = 0;
    for (char c : input) {
        num = num * 10 + (c - '0');
    }
    
    if (num < 1 || num > 10) {
        return false;
    }
    
    return true;
}

int main() {
    string input;
    int num = 0;

    while (true) {
        cout << "Enter an integer between 1 and 10: ";
        getline(cin, input);

        if (isValidInteger(input, num)) {
            break;
        } else {
            cout << "Invalid input, try again." << endl;
        }
    }

    cout << "Entered a valid integer: " << num << endl;
    return 0;
}


