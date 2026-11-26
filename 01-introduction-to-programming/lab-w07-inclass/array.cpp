#pragma once
#include "array.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


void doc(int a[], int& n) {
	
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
}
void xulyp01(int a[], int n) {
	
	int le = 1e9;
	int chan = -1e9;
	for (int i = 1;i <= n;i++) {
		if (a[i] % 2 == 1 && a[i] < le) le = a[i];
		if (a[i] % 2 == 0 && a[i] > chan) chan = a[i];
	}
		cout << chan << " " << le;
}

void xulyp02(int a[], int n) {

	double dem = 0;
	double sum = 0;
	for (int i=1;i<=n;i++)
		if (a[i] % 2 == 0) {
			sum += a[i];
			dem++;
		}
	if (dem == 0) cout << 0;
	else cout << setprecision(02) << fixed << sum / dem<<endl;
}

int check(int k) {
	
	int dem = 0;
	for (int i = 2;i <= sqrt(k);i++)
		if (k % i == 0) dem++;
	if (dem == 0) return 1;
	else return 0;
}

void xulyp04(int a[], int n) {
	
	int sl = 0;
	for (int i = 1;i <= n;i++) {
		if (check(a[i] == 1)) {
			sl++;
		}
		else a[i] = 0;
	}
	cout << sl << endl;
	for (int i = 1;i <= n;i++)
		if (a[i] != 0) cout << a[i] << " ";
}
