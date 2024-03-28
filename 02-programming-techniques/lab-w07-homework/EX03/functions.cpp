#include "functions.h"


const int MAX_N = 10; 

const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int board[MAX_N][MAX_N];

bool isValidMove(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0);
}

bool findKnightTour(int x, int y, int moveCount, int N) {
    if (moveCount == N * N) {
        return true;
    }

    for (int i = 0; i < 8; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isValidMove(nextX, nextY, N)) {
            board[nextX][nextY] = moveCount + 1;
            if (findKnightTour(nextX, nextY, moveCount + 1, N)) {
                return true;
            }
            board[nextX][nextY] = 0;
        }
    }
    return false;
}

void knightTour(int N) {
    memset(board, 0, sizeof(board));
    board[0][0] = 1;
    if (findKnightTour(0, 0, 1, N)) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << board[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution exists!" << std::endl;
    }
}
