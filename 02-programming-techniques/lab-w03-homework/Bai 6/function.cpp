# include "header.h" 
int* createAndInitialize(int* array, int size) {
    int newSize = size * 2;
    int* newArray = (int*)malloc(newSize * sizeof(int));

    if (newArray == NULL) {
        printf("error");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    for (int i = size; i < newSize; i++) {
        newArray[i] = 0;
    }

    return newArray;
}

