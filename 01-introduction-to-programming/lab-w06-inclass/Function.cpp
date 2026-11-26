#include "Function.h"

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
