#include "functions.h"
using namespace std; 
int main() {
    int N;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> N;

    knightTour(N);

    return 0;
}
