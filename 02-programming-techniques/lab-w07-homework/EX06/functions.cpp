#include "functions.h"


void backtrack(int permutation[], bool used[], int current, int N) {
    if (current == N) {
        for (int i = 0; i < N; ++i) {
            std::cout << permutation[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (!used[i]) {
            permutation[current] = i;
            used[i] = true;
            backtrack(permutation, used, current + 1, N);
            used[i] = false;
        }
    }
}

void printPermutations(int N) {
    int permutation[N];
    bool used[N + 1] = {false};

    backtrack(permutation, used, 0, N);
}
