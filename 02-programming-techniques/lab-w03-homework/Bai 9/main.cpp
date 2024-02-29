#include <stdio.h>
#include "header.h"

int main() {
    int n;
    printf("Nhap so luong con khi: ");
    scanf("%d", &n);

    double food[n][7];
    

    double averageFood = calculateAverageFood(food, n);
    double minFood = findMinFood(food, n);
    double maxFood = findMaxFood(food, n);

    printf("\nBáo cáo:\n");
    printf("Lư?ng th?c ăn trung b?nh m?i ngày c?a gia đ?nh kh?: %.2lf\n", averageFood);
    printf("Lư?ng th?c ăn ít nh?t trong tu?n: %.2lf\n", minFood);
    printf("Lư?ng th?c ăn nhi?u nh?t trong tu?n: %.2lf\n", maxFood);

    return 0;
}
