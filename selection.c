#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    for (int step = 0; step < n - 1; step++) {
        int min_idx = step;
        for (int j = step + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[step];
        arr[step] = temp;
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {20, 12, 10, 15, 2};
    int n = sizeof(data) / sizeof(data[0]);
    
    // Call selection sort function
    selectionSort(data, n);
    
    // Print the sorted array
    printf("Sorted array in Ascending Order:\n");
    printArray(data, n);
    
    return 0;
}