#include <iostream>

void printPattern(int n, int m) {
   
    if (n <= 0 || n == m) {
        std::cout << n << " ";
        return;
    }

    
    std::cout << n << " ";
    printPattern(n - 5, m);

    
    if (n != m) {
        
        std::cout << n << " ";
    }
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    
    printPattern(n, 0);
    printPattern(n, n);

    return 0;
}
