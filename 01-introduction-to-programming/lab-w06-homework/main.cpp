#include <iostream>
#include "Function.h"
using namespace std;

int main() {
	int k;
	do {
		cout << "Chon bai (44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 95, 96; 0 de thoat): ";
		if (!(cin >> k)) break;

		if (k == 44) {
			int n;
			cin >> n;
			cout << tongcs(n) << endl;
		}
		else if (k == 48) {
			int n;
			cin >> n;
			cout << tich(n) << endl;
		}
		else if (k == 52) {
			int n;
			cin >> n;
			cout << mi(n) << endl;
		}
		else if (k == 56) {
			int n;
			cin >> n;
			cout << (checkchan(n) == 1 ? "YES" : "NO") << endl;
		}
		else if (k == 60) {
			int a, b;
			cin >> a >> b;
			cout << ucln(a, b) << endl;
		}
		else if (k == 64) {
			// S = -(x^2 + x^4 + ... ), even powers up to n
			double x;
			int n;
			cin >> x >> n;
			double kq = 0;
			for (int i = 2; i <= n; i += 2) kq -= Pow(x, i);
			cout << kq << endl;
		}
		else if (k == 68) {
			// S = -(x/1! + x^2/2! + ... + x^n/n!)
			double x;
			int n;
			cin >> x >> n;
			double sum = 0;
			for (int i = 1; i <= n; i++) sum -= Pow(x, i) / gt(i);
			cout << sum << endl;
		}
		else if (k == 72) {
			int n;
			cin >> n;
			cout << (k3(n) == 1 ? "YES" : "NO") << endl;
		}
		else if (k == 76) {
			int day, month, year, n;
			cin >> day >> month >> year >> n;
			addDay(day, month, year, n);
			cout << day << " " << month << " " << year << endl;
		}
		else if (k == 80) {
			// Nearest prime to n (n itself if n is prime)
			int n;
			cin >> n;
			if (checknt(n) == 1) {
				cout << n << endl;
				continue;
			}
			int before = 0;
			for (int i = n - 1; i >= 2; i--)
				if (checknt(i) == 1) {
					before = i;
					break;
				}
			int after = n + 1;
			while (checknt(after) == 0) after++;
			if (before != 0 && n - before <= after - n) cout << before << endl;
			else cout << after << endl;
		}
		else if (k == 95) {
			float a, b, c, x1, x2;
			cin >> a >> b >> c;
			if (a == 0) {
				cout << "a phai khac 0" << endl;
				continue;
			}
			int numNo = giaiPT(a, b, c, x1, x2);
			if (numNo == 0) cout << "Phuong trinh da cho vo nghiem" << endl;
			else if (numNo == 1) cout << "Phuong trinh da cho co nghiem kep x = " << x1 << endl;
			else cout << "Phuong trinh da cho co hai nghiem phan biet " << x1 << " " << x2 << endl;
		}
		else if (k == 96) {
			// Next day
			int ngay, thang, nam;
			cin >> ngay >> thang >> nam;
			addDay(ngay, thang, nam, 1);
			cout << ngay << " " << thang << " " << nam << endl;
		}
	} while (k != 0);
	return 0;
}
