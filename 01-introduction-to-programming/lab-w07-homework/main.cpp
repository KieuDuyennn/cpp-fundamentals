#include <iostream>
#include <iomanip>
#include<algorithm>
#include "array.h"
using namespace std;
int main() {
    int choice = 0;
    while (true) {
        cout << "1. Do  P01" << endl;
        cout << "2. Do  P02" << endl;
        cout << "4. Do  P04" << endl;
        cout << "5. Do  P05" << endl;
        cout << "6. Do  P06" << endl;
        cout << "9. Do  P09" << endl;
        cout << "12. Do  P012" << endl;
        cout << "15. Do  P15" << endl;
        cout << "25. Do  P25" << endl;
        cout << "26. Do  P26" << endl;
        cout << "0. Exit" << endl;

        cout << "Your choice: ";
        cin >> choice;

        int  n, a[10005];
        if (choice == 1) {
            cout << "Doing  P01" << endl;
            doc(a, n);
            xulyp01(a, n);
            cout << endl;
        }
        else if (choice == 2) {
            cout << "Doing P02" << endl;


            doc(a, n);
            xulyp02(a, n);
            cout << endl;
        }
        else if (choice == 4) {
            cout << "Doing P04" << endl;


            doc(a, n);
            xulyp04(a, n);
            cout << endl;
        }

        else if (choice == 5) {
            cout << "Doing P05" << endl;


            doc(a, n);
            xulyp05(a, n);
            cout << endl;
        }

        else if (choice == 6) {
            cout << "Doing P06" << endl;


            doc(a, n);
            xulyp06(a, n);
            cout << endl;
        }

        else if (choice == 9) {
            cout << "Doing P09" << endl;


            doc(a, n);
            xulyp09(a, n);
            cout << endl;
        }

        else if (choice == 12) {
            cout << "Doing P12" << endl;


            doc(a, n);
            xulyp12(a, n);
            cout << endl;
        }
        else if (choice == 15) {
            cout << "Doing P15" << endl;


            doc(a, n);
            xulyp15(a, n);
            cout << endl;
        }

        else if (choice == 25) {
            cout << "Doing P25" << endl;
            xulyp25();
            cout << endl;
        }

        else if (choice == 26) {
            cout << "Doing P26" << endl;
            xulyp26();
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
