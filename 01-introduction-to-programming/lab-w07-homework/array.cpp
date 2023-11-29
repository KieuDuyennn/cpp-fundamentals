#pragma once
#include "array.h"
#include <iostream>
#include <iomanip>
#include<algorithm>
#include <math.h> 
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
	for (int i = 1;i <= n;i++)
		if (a[i] % 2 == 0) {
			sum += a[i];
			dem++;
		}
	if (dem == 0) cout << 0;
	else cout << setprecision(02) << fixed << sum / dem << endl;
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

void xulyp05(int a[], int n) {
	for (int i = 1;i <= n - 1;i++)
		for (int j = i + 1;j <= n;j++)
			if (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j]) swap(a[i], a[j]);
	cout << n << endl;
	for (int i = 1;i <= n;i++) cout << a[i] << " ";
}

void xulyp06(int a[], int n) {
	int tang = 0, giam = 0, t = 0;
	for (int i = 1;i <= n - 1;i++)
	{
		if (a[i] < a[i + 1]) tang++;
		if (a[i] > a[i + 1]) giam++;
		else t++;
	}
	if (tang == n - 1) cout << "Day tang";
	if (giam == n - 1) cout << "Day giam";
	else cout << "Khong tang khong giam";
}

void xulyp09(int a[], int n) {
	int dem = 0;
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n - 1;i++)
		if (a[i] != a[i + 1]) dem++;
	cout << dem + 1;
}

void xulyp12(int a[], int n) {
	sort(a + 1, a + n + 1);
	int dem = 0;
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n - 1;i++)
		if (a[i] == a[n]) dem++;
	cout << a[n - dem - 1];
}

void xulyp15(int a[], int n) {
	for (int i = 1;i <= n / 2;i++) swap(a[i], a[n - i + 1]);
	for (int i = 1;i <= n;i++) cout << a[i] << " ";
}

void xulyp25() {
	long long  n, m, a[10009], b[10009];
	long long c[10009];
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) cin >> b[i];

	for (int i = 1;i <= n;i++) c[i] = a[i];
	for (int i = n + 1;i <= m + n;i++) c[i] = b[i - n];
	sort(c + 1, c + n + m + 1);
	for (int i = 1;i <= m + n;i++) cout << c[i] << " ";
}
void xulyp26() {
	long long  n, m, a[10009], b[10009];
	long long c[10009];
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) cin >> b[i];

	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (a[i] == b[j]) cout << a[i] << " ";
}
