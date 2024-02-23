#include "header3.h" 
int main()
{
    const int size = 100;
    char str[size];

    std::cout << "Enter a string: ";
    std::cin.getline(str, size);

    if(isPalindrome(str))
        std::cout << "The string is a palindrome." << std::endl;
    else
        std::cout << "The string is not a palindrome." << std::endl;

   return 0;
}
