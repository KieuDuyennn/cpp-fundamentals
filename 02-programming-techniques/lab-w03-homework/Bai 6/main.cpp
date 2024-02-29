# include "header.h" 
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int* newArr = createAndInitialize(arr, size);
    
    if (newArr != NULL) {
        for (int i=0; i<size*2; i++) {
            printf("%d ", newArr[i]);
        }
        
        free(newArr);
     }
     
     return 0;
}
