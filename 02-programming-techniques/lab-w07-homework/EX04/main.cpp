#include "functions.h"
using namespace std;
int main() {
    int N, istart, jstart, iend, jend;
    std::cout << "Enter the size of the chessboard (N x N): ";
    std::cin >> N;
    std::cout << "Enter the start cell (istart, jstart): ";
    std::cin >> istart >> jstart;
    std::cout << "Enter the end cell (iend, jend): ";
    std::cin >> iend >> jend;

    knightTour(N, istart, jstart, iend, jend);

    return 0;
}
