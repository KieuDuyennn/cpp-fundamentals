#include "Function.h"
#include <cmath>

int tongcs(int n) {
	int s = 0;
	while (n != 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

int tich(int n) {
	int res = 1;
	while (n != 0) {
		int k = n % 10;
		if (k % 2 == 1) res *= k;
		n /= 10;
	}
	return res;
}

int mi(int n) {
	int Mi = 9;
	do {
		int k = n % 10;
		if (k < Mi) Mi = k;
		n /= 10;
	} while (n != 0);
	return Mi;
}

int checkchan(int n) {
	while (n != 0) {
		if ((n % 10) % 2 == 0) return 0;
		n /= 10;
	}
	return 1;
}

int ucln(int a, int b) {
	a = std::abs(a);
	b = std::abs(b);
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

double Pow(double a, int b) {
	double tich = 1;
	for (int i = 1; i <= b; i++) tich *= a;
	return tich;
}

long long gt(int k) {
	long long giaithua = 1;
	for (int i = 2; i <= k; i++) giaithua *= i;
	return giaithua;
}

int k3(int n) {
	if (n <= 0) return 0;
	while (n % 3 == 0) n /= 3;
	return n == 1 ? 1 : 0;
}

void addDay(int& day, int& month, int& year, int n) {
	while (n > 0) {
		int daysInMonth = 31;
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			daysInMonth = 30;
		}
		else if (month == 2) {
			bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
			daysInMonth = leap ? 29 : 28;
		}

		if (n >= daysInMonth - day + 1) {
			n -= daysInMonth - day + 1;
			day = 1;
			if (month == 12) {
				month = 1;
				year++;
			}
			else {
				month++;
			}
		}
		else {
			day += n;
			n = 0;
		}
	}
}

int checknt(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}

int giaiPT(float a, float b, float c, float& x1, float& x2) {
	float delta = b * b - 4 * a * c;
	if (delta < 0) {
		x1 = x2 = 0.0f;
		return 0;
	}
	if (delta == 0) {
		x1 = x2 = -b / (2 * a);
		return 1;
	}
	delta = std::sqrt(delta);
	x1 = (-b + delta) / (2 * a);
	x2 = (-b - delta) / (2 * a);
	return 2;
}
