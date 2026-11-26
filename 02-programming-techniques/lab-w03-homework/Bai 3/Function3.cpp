#include <cstring>
bool isPalindrome(char* cstr)
{
    char* front = cstr;
    char* back = cstr + strlen(cstr)-1;
    while (front < back)
    {
        if (*front != *back)
            return 0;
        front++;
        back--;
    }
    return 1;
} 
