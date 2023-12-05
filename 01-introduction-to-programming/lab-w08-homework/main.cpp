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
        cout << "398. Do  P398" << endl;
        cout << "402. Do  P402" << endl;
        cout << "423. Do  P423" << endl;
        cout << "438. Do  P438" << endl;
        cout << "457. Do  P457" << endl;
        cout << "458. Do  P458" << endl;
        cout << "471. Do  P471" << endl;
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
        else if (choice == 398) {
            cout << "Doing P398" << endl;
            p398();
            cout << endl;
        }
        else if (choice == 402) {
            cout << "Doing 402" << endl;
            p402();
            cout << endl;
        }
        else if (choice == 423) {
            cout << "Doing 423" << endl;
            p423();
            cout << endl;
        }

        else if (choice == 457) {
            cout << "Doing 457" << endl;
            p457();
            cout << endl;
        }
        else if (choice == 458) {
            cout << "Doing 458" << endl;
            p458();
            cout << endl;
        }
        else if (choice == 471) {
            cout << "Doing 471" << endl;
            p471();
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
