#include <iostream>
using namespace std;

int C(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > 0 && k < n) {
        return C(n - 1, k) + C(n - 1, k - 1);
    }
    return 0; 
}

int main() {
    int n, k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;
    cout << "C(" << n << ", " << k << ") = " << C(n, k) << endl;

    return 0;
}

