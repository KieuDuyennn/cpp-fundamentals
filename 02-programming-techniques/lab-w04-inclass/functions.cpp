#include <stdio.h>
#include "functions.h" 

void saveArrayToFile(int arr[], int n, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(&n, sizeof(int), 1, file); 
        fwrite(arr, sizeof(int), n, file); 
        fclose(file);
        printf("Array saved to %s\n", filename);
    } else {
        printf("Error opening file for writing.\n");
    }
}


void loadArrayAndFindMedian(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        int n;
        fread(&n, sizeof(int), 1, file); 
        int arr[n];
        fread(arr, sizeof(int), n, file); 
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    	double median;
        if (n % 2 == 0) {
            median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        } else {
            median = arr[n / 2];
        }

        printf("Median: %.2lf\n", median);
        fclose(file);
    } else {
        printf("Error opening file for reading.\n");
    }
}

       
        

