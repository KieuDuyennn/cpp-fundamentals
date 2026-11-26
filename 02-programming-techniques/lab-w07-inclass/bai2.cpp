// N-queens: print every way to place N queens on an N x N board so that no two attack each other.
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20;
int N, X[MAX + 1], col[MAX + 1], pDia[2 * MAX + 1], sDia[2 * MAX + 1];
int a[MAX + 1][MAX + 1];

void inkq() {
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= N; i++) {
		a[i][X[i]] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// Place the queen of row i, then recurse into row i + 1.
void Try(int i) {
	for (int j = 1; j <= N; j++) {
		if (col[j] == 0 && pDia[i - j + N] == 0 && sDia[i + j - 1] == 0) {
			X[i] = j;
			col[j] = pDia[i - j + N] = sDia[i + j - 1] = 1;
			if (i == N)
				inkq();
			else
				Try(i + 1);
			// backtrack
			col[j] = pDia[i - j + N] = sDia[i + j - 1] = 0;
		}
	}
}

int main() {
	cin >> N;
	if (N < 1 || N > MAX) {
		cout << "N must be between 1 and " << MAX << endl;
		return 1;
	}
	Try(1);
	return 0;
}
