# include "header.h" 
double findMedian(int* arr, int n) {
    if (n % 2 != 0)
        return (double)*(arr + n / 2);
    else
        return (*(arr + (n - 1) / 2) + *(arr + n / 2)) / 2.0;
} 
