
#include "function.h"
int tongcs(int n) {
	int s = 0;
	while (n != 0) {
		s += n % 10;
		n = n / 10;
	}
	return s;
}
int tich(int n) {
	int res = 1;
	while (n != 0) {
		int k = n % 10;
		if (k % 2 == 1) {
			res *= k;
			n = n / 10;
		}
		else n = n / 10;
	}
	return res;
}
int mi(int n) {
	int Mi = 10;
	int k;
	while (n != 0)
	{
		k = n % 10;
		if (k == 0) { return 0;break; }
		else {

			if (k < Mi) {
				Mi = k;
				n = n / 10;
			}
			else n = n / 10;
		}
	}
	return Mi;
}
