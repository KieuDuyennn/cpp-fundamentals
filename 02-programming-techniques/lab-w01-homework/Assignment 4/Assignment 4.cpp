#include <iostream>
#include <algorithm>

int main() {
    int n, d;
    std::cin >> n >> d;

    int b[2000];
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    int moves = 0;
    for (int i = 1; i < n; ++i) {
        if (b[i] <= b[i - 1]) {
            int diff = b[i - 1] - b[i];
            int requiredMoves = diff / d + 1;
            b[i] += requiredMoves * d;
            moves += requiredMoves;
        }
    }

    std::cout << moves << std::endl;

    return 0;
}
