#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX_N 1001

using namespace std;

int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int solveTopDown(int M, int N, int i, int j) {
	if (i == M) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = solveTopDown(M, N, i + 1, j) + a[i][j];
	if (j - 1 >= 0)
		dp[i][j] = max(dp[i][j], solveTopDown(M, N, i + 1, j - 1) + a[i][j]);
	if (j + 1 < N)
		dp[i][j] = max(dp[i][j], solveTopDown(M, N, i + 1, j + 1) + a[i][j]);
	return dp[i][j];
}

int solveBottomUp(int M, int N) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == 0) dp[i][j] = a[i][j];
			else {
				dp[i][j] = dp[i - 1][j] + a[i][j];
				if (j > 0)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
				if (j < N - 1)
					dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + a[i][j]);
			}
		}
	}
	int res = 0;
	for (int j = 1; j < N; ++j)
		if (dp[M - 1][j] > dp[M - 1][res])
			res = j;
	return res;
}

void traceTopDown(int M, int N, int col) {
	int row = 0;
	while (row < M) {
		cout << "Lau " << row + 1 << " Phong " << col + 1 ;
		if (row == M - 1) break;
		else cout << " -> ";
		if (dp[row][col] == dp[row + 1][col] + a[row][col]) {
		}
		else if (col > 0 && dp[row][col] == dp[row + 1][col - 1] + a[row][col]) {
			--col;
		}
		else {
			++col;
		}
		++row;
	}
}

void traceBottomUp(int M, int N, int row, int col) {
	if (row == 0) {
		cout << "Lau " << 1 << " Phong " << col + 1;
		return;
	}
	if (dp[row][col] == dp[row - 1][col] + a[row][col])
		traceBottomUp(M, N, row - 1, col);
	else if (col > 0 && dp[row][col] == dp[row - 1][col - 1] + a[row][col])
		traceBottomUp(M, N, row - 1, col - 1);
	else
		traceBottomUp(M, N, row - 1, col + 1);
	cout << " -> ";
	cout << " Lau " << row + 1 << " Phong " << col + 1 ;

}

void TopDown(int M, int N) {
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			dp[i][j] = -1;
	int col = 0;
	for (int i = 1; i < N; ++i)
		if (solveTopDown(M, N, 0, i) > solveTopDown(M, N, 0, col))
			col = i;

	cout << "So vang toi da la " << solveTopDown(M, N, 0, col) << endl;
	traceTopDown(M, N, col);
	cout << endl;
}

void BottomUp(int M, int N) {
	int col = solveBottomUp(M, N);
	cout << "So vang toi da la " << dp[M - 1][col] << endl;
	traceBottomUp(M, N, M - 1, col);
}

int main() {
	int M, N;
	cout << "Nhap so tang cua toa thap M = ";
	cin >> M;
	cout << "Nhap so phong cua moi tang N = ";
	cin >> N;
	cout << "Nhap so vang cua cac phong (duoi dang ma tran): " << endl;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> a[i][j];
	TopDown(M, N);
	BottomUp(M, N);
	return 0;
}
