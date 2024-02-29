#include "header.h"

double calculateAverageFood(double food[][7], int n) {
    double totalFood = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            totalFood += food[i][j];
        }
    }
    return totalFood / (n * 7);
}

double findMinFood(double food[][7], int n) {
    double minFood = food[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            if (food[i][j] < minFood) {
                minFood = food[i][j];
            }
        }
    }
    return minFood;
}

double findMaxFood(double food[][7], int n) {
    double maxFood = food[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            if (food[i][j] > maxFood) {
                maxFood = food[i][j];
            }
        }
    }
    return maxFood;
}
