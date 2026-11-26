#include <iostream>
using namespace std;

// Taxi fare: first km 15,000; km 2-6: 13,500/km; km 7-120: 11,000/km; over 120 km: 10% off.
int main() {
	int km;
	cin >> km;
	if (km <= 1) cout << 15000;
	else if (km <= 6) cout << 15000 + (km - 1) * 13500;
	else if (km <= 120) cout << 15000 + 13500 * 5 + (km - 6) * 11000;
	else cout << (15000 + 13500 * 5 + (km - 6) * 11000) * 0.9;
	return 0;
}
