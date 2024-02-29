# include "header.h" 
int main() {
    int values[] = {1, 3, 3, 6, 7, 8, 9};
    int n = sizeof(values)/sizeof(values[0]);
    
    printf("Median = %.2f", findMedian(values, n));
    
    return 0;
}
