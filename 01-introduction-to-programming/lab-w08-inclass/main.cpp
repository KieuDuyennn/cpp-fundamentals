#include <iostream>
#include <iomanip>
#include "array.h"
using namespace std;
int main() {
    int choice = 0;
    while (true) {
        cout << "320. Do  P320" << endl;
        cout << "342. Do  P342" << endl;
        cout << "347. Do  P347" << endl;
        cout << "0. Exit" << endl;

        cout << "Your choice: ";
        cin >> choice;


        if (choice == 320) {
            cout << "Doing  P320" << endl;
            p320();
            cout << endl;
        }
        else if (choice == 342) {
            cout << "Doing P342" << endl;
            p342();
            cout << endl;
        }
        else if (choice == 347) {
            cout << "Doing P347" << endl;
            p347();
            cout << endl;
        }
        else if (choice == 0) {
            cout << "Exiting" << endl;
            break;
        }
        else {
            cout << "Incorrect" << endl;
        }
    }
    return 0;
}
