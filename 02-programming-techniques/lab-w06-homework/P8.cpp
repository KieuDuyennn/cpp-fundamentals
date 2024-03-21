#include <iostream>
#include <unordered_set>

std::unordered_set<int> recamanSet;

int recaman(int n, int prev, int i) {
    if (n <= 0)
        return 0;
    if (prev - i > 0 && recamanSet.find(prev - i) == recamanSet.end()) {
        recamanSet.insert(prev - i);
        std::cout << prev - i << " ";
        return recaman(n - 1, prev - i, i + 1);
    } else {
        recamanSet.insert(prev + i);
        std::cout << prev + i << " ";
        return recaman(n - 1, prev + i, i + 1);
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "Recaman's sequence: ";
    recaman(n, 0, 1);
    std::cout << std::endl;
    return 0;
}
