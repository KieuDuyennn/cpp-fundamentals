#include <stdio.h>
#include "header.h"

#define MAX_MONKEYS 100

int main() {
    int n;
    printf("Nhap so luong con khi (1-%d): ", MAX_MONKEYS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_MONKEYS) {
        printf("So luong khong hop le.\n");
        return 1;
    }

    double food[MAX_MONKEYS][7];
    for (int i = 0; i < n; i++) {
        printf("Nhap luong thuc an 7 ngay cua con khi thu %d: ", i + 1);
        for (int j = 0; j < 7; j++) {
            if (scanf("%lf", &food[i][j]) != 1) {
                printf("Du lieu khong hop le.\n");
                return 1;
            }
        }
    }

    double averageFood = calculateAverageFood(food, n);
    double minFood = findMinFood(food, n);
    double maxFood = findMaxFood(food, n);

    printf("\nBao cao:\n");
    printf("Luong thuc an trung binh moi ngay cua gia dinh khi: %.2lf\n", averageFood);
    printf("Luong thuc an it nhat trong tuan: %.2lf\n", minFood);
    printf("Luong thuc an nhieu nhat trong tuan: %.2lf\n", maxFood);

    return 0;
}
