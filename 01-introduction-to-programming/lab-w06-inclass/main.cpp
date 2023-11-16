#include <iostream>
#include "Function.h"
using namespace std;
int main() {

	int k;
	
	do {
		cout << "Nhap 44, 48 hoac 52 ";
		cin >> k;
		if (k == 44) {
			int n;
			cin >> n;
			cout << tongcs(n);
			
		}
		if (k == 48) {
			int n;
			cin >> n;
			cout << tich(n);
			
		}
		if (k == 52) {
			int n;
			cin >> n;
			cout << mi(n);
			
		}
	} while (k != 0);
	
}
