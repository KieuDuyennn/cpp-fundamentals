#include <iostream>

void outputArray(int arr[], int size, int index = 0) {
    if (index == size)
        return;
    std::cout << arr[index] << " ";
    outputArray(arr, size, index + 1);
}


void outputReversedArray(int arr[], int size, int index) {
    if (index < 0)
        return;
    std::cout << arr[index] << " ";
    outputReversedArray(arr, size, index - 1);
}


int sumOfPositive(int arr[], int size, int index = 0) {
    if (index == size)
        return 0;
    int current = arr[index] > 0 ? arr[index] : 0;
    return current + sumOfPositive(arr, size, index + 1);
}

// Function to check if a value exists in the array
bool existsInArray(int arr[], int value, int index) {
    if (index < 0)
        return false;
    if (arr[index] == value)
        return true;
    return existsInArray(arr, value, index - 1);
}


int countDistinct(int arr[], int size, int currentIndex) {
    if (currentIndex < 0)
        return 0;
    if (!existsInArray(arr, arr[currentIndex], currentIndex - 1))
        return 1 + countDistinct(arr, size, currentIndex - 1);
    return countDistinct(arr, size, currentIndex - 1);
}

int main() {
    const int maxSize = 100;
    int arr[maxSize];
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::cout << "Enter " << size << " integer values: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Array of integer values: ";
    outputArray(arr, size);
    std::cout << std::endl;

    std::cout << "Array of integer values in reversed order: ";
    outputReversedArray(arr, size - 1, size - 1);
    std::cout << std::endl;

    std::cout << "Sum of positive numbers in the array: " << sumOfPositive(arr, size) << std::endl;

    std::cout << "Number of distinct values in the array: " << countDistinct(arr, size, size - 1) << std::endl;

    return 0;
}
