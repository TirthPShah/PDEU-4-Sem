#include <stdio.h>
#include <time.h>

int findMinIndex (int arr[], int start, int n) {

    int minIndex = start;
    int minValue = arr[start];

    for (int i = start; i < n; i++) {
        if (minValue > arr[i]) {
            minValue = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void selectionSort (int arr[], int n) {

    for (int i = 0; i < n; i++) {

        int currPos = i;
        int minIndex = findMinIndex(arr, currPos, n);

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

    }

}

int main() {

    clock_t start, end;

    int arr[] = {8, 9, 1, 10, 3, 7, 2};
    int n = 7;

    start = clock();
    
    selectionSort(arr, n);

    end = clock();

    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}