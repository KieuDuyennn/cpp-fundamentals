#include "main.h"

int main() {
    const string correctPassword = "password"; // Example password
    string userInput;
    int attempts = 3;

    cout << "Please enter your password.\n";

    while (attempts > 0) {
        cout << "Enter password: ";
        cin >> userInput;

        if (userInput == correctPassword) {
            cout << "Password accepted! Welcome to the main screen.\n";
            
            break; 
        } else {
            attempts--;
            cout << "Wrong password. You have " << attempts << " attempts left.\n";
        }
    }

    if (attempts == 0) {
        cout << "Too many wrong attempts. Exiting the program.\n";
    }

    return 0;
}
