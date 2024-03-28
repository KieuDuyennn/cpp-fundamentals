
#include "functions.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <string.h>
const int MAX_N = 8;
int X[MAX_N + 1];
bool col[MAX_N + 1], pDia[2 * MAX_N + 1], sDia[2 * MAX_N + 1];


bool canPlace(int i, int j) {
    return !col[j] && !pDia[i + j] && !sDia[i - j + MAX_N];
}

void printSolution(int N) {
    for (int i = 1; i <= N; ++i)
        cout << "(" << i << "," << X[i] << ") ";
    cout << endl;
}

void solve(int row, int N) {
    if (row > N) {
        printSolution(N);

    }
   
    for (int j = 1; j <= N; ++j) {
        if (canPlace(row, j)) {
            X[row] = j;
            col[j] = pDia[row + j] = sDia[row - j + MAX_N] = true;
            solve(row + 1, N);
            col[j] = pDia[row + j] = sDia[row - j + MAX_N] = false;
        }
    }
}

void solveEightQueens(int N) {
    memset(col, false, sizeof(col));
    memset(pDia, false, sizeof(pDia));
    memset(sDia, false, sizeof(sDia));
    solve(1, N);
}
