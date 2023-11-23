#include <iostream>
#include <iomanip>
#include "array.h"
using namespace std;
int main() {
    int choice = 0;
    while (true) {
        cout << "1. Do  P01" << endl;
        cout << "2. Do  P02" << endl;
        cout << "4. Do  P04" << endl;
        cout << "0. Exit" << endl;

        cout << "Your choice: ";
        cin >> choice;
        
        int n, a[100005];
        if (choice == 1) {
            cout << "Doing  P01" << endl;
            doc(a, n);
            xulyp01(a, n);
        }
        else if (choice == 2) {
            cout << "Doing P02" << endl;
    
            
            doc(a, n);
            xulyp02(a, n);
        }
        else if (choice == 4) {
            cout << "Doing P04" << endl;
           
           
            doc(a, n);
            xulyp04(a, n);
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
