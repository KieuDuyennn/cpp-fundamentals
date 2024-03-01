#include "functions.h" 
int main() {

    int choice;
    printf("1. Enter an array and save to binary file\n");
    printf("2. Load array from binary file and find median\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int n;
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        saveArrayToFile(arr, n, "input.bin");
    } else if (choice == 2) {
        loadArrayAndFindMedian("input.bin");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

