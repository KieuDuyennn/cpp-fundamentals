#include <iostream>
#include <cstring>

bool isPalindrome(int l, int r, char* s) {
    if (l >= r)
        return true;
    if (s[l] != s[r])
        return false;
    return isPalindrome(l + 1, r - 1, s);
}

int main() {
    const int MAX_LENGTH = 100; 
    char str[MAX_LENGTH + 1];  
    std::cout << "Enter a string: ";
    std::cin.getline(str, MAX_LENGTH + 1); 

    int length = strlen(str);
    
    if (isPalindrome(0, length - 1, str))
        std::cout << "The string is a palindrome." << std::endl;
    else
        std::cout << "The string is not a palindrome." << std::endl;
    
    return 0;
}
