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
