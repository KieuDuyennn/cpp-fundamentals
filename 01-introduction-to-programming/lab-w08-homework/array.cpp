#include "array.h"
#include <iostream>
#include <iomanip>
using namespace std;


void p320() {
	double a[104][104];
	int m, n;
	cin >> m >> n;
	double sum = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j] > 0) sum += a[i][j];
	cout << "Tong cac so thuc duong trong ma tran la " << sum;
}
void p342() {
	double a[104][104];
	int m, n;
	cin >> m >> n;
	int dem = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	for (int i = 1;i < m - 1;i++)
		for (int j = 1;j < n - 1;j++)
			if (a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i + 1][j + 1] && a[i][j] > a[i - 1][j + 1] && a[i][j] > a[i - 1][j - 1] && a[i][j] > a[i + 1][j - 1])
				dem++;
	cout << dem;

}

void p347() {
	double a[104][104];
	int m, n;
	cin >> m >> n;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	int cnt = 0;

	for (int i = 0; i < m; i++)
	{
		int max = a[i][0];
		int col = 0;
		for (int j = 1; j < n; j++)
		{

			if (max < a[i][j])
			{
				max = a[i][j];
				col = j;
			}
		}


		int  min = a[0][col];
		for (int t = 1; t < m; t++)
		{
			if (min > a[t][col])
			{
				min = a[t][col];
			}
		}


		if (max == min)
		{
			cnt++;
		}
	}
	cout << cnt;

}
void p398() {
	double a[104][104];
	int m, n;
	cin >> m >> n;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	// Rotate the border one step counterclockwise.
	int i = 0, j = 0;
	double tam = a[0][0];
	for (; i < m - 1; i++)
	{
		a[i][j] = a[i + 1][j];
	}
	for (; j < n - 1; j++)
	{
		a[i][j] = a[i][j + 1];
	}
	for (; i > 0; i--)
	{
		a[i][j] = a[i - 1][j];
	}
	for (; j > 1; j--)
	{
		a[i][j] = a[i][j - 1];
	}
	a[0][1] = tam;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void p402() {
	double a[104][104];
	int m, n;
	cin >> m >> n;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	for (int i = m - 1;i >= 0;i--)
	{
		for (int j = 0;j < n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void p423() {
	int m, n;
	cin >> m >> n;
	int a[100][100];
	int dong = m, cot = n, k = 1, p = 0, i, j;
	while (k <= m * n) {
		for (i = p; i < cot; i++)
			a[p][i] = k++;
		for (i = p + 1; i < dong; i++)
			a[i][cot - 1] = k++;
		if (p != dong - 1) {
			for (i = cot - 2; i >= p; i--)
				a[dong - 1][i] = k++;
		}
		if (p != cot - 1) {
			for (i = dong - 2; i > p; i--)
				a[i][p] = k++;
		}
		p++;dong--; cot--;
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

// 1 if the matrix is symmetric across the main diagonal, otherwise 0
int kiemtradoixung(int a[100][100], int n)
{
	for (int k = 0; k < n; k++)
		for (int j = k + 1; j < n; j++)
			if (a[k][j] != a[j][k]) return 0;
	return 1;
}
void p457() {
	int a[100][100];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cin >> a[i][j];
		}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}
	if (kiemtradoixung(a, n) == 1)
		cout << " ma tran co doi xung qua duong cheo chinh";
	else
		cout << " ma tran khong doi xung qua duong cheo chinh";
}

int CheoPhu(int a[100][100], int n) {
	int check = 1;
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - 1;j++)
		{
			if (a[i][j] != a[n - 1 - j][n - 1 - i]) {
				check = 0;
				break;
			}
		}
	}

	return check;
}

void p458() {
	int a[100][100];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cin >> a[i][j];
		}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}
	if (CheoPhu(a, n) == 1)
		cout << " ma tran co doi xung qua duong cheo phu";
	else
		cout << " ma tran khong doi xung qua duong cheo phu";
}

void intput(int n, int m, int a[][100]) {
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++) {
			cin >> a[i][j];
		}
	}
}

void output(int n, int m, int a[][100]) {
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}

void tichMaTran(int a[][100], int b[][100], int m, int n, int m1) {
	int c[100][100];
	int i, j, k;
	for (i = 0;i < n;i++)
		for (j = 0;j < m1;j++) {
			int tt = 0;
			for (k = 0;k < m;k++)
			{
				tt = tt + (a[i][k] * b[k][j]);
			}
			c[i][j] = tt;
		}


	output(n, m1, c);
}

void p471() {
	int n, m;
	cin >> n >> m;
	int a[100][100];
	intput(n, m, a);

	int n1, m1;
	cin >> n1 >> m1;
	int b[100][100];

	intput(n1, m1, b);



	output(n, m, a);

	output(n, m, b);

	if (m == n1) {
		tichMaTran(a, b, m, n, m1);
	}
	else {
		cout << "So cot Ma tran A khac so hang ma tran B, khong the nhan 2 ma tran nay";
	}
}
