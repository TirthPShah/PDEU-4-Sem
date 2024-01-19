#include <stdio.h>
#include <time.h>

void merge (int arr[], int start, int end) {

    int mid = start + (end - start) / 2;

    int arrLeftSize = mid - start + 1;
    int arrRightSize = end - mid;

    int arrLeft[arrLeftSize];
    int arrRight[arrRightSize];

    for (int i = 0; i < arrLeftSize; i++) {
        arrLeft[i] = arr[start + i];
    }

    for (int i = 0; i < arrRightSize; i++) {
        arrRight[i] = arr[mid + 1 + i];
    }

    int k = start;
    int currLeft = 0;
    int currRight = 0;

    while (currLeft < arrLeftSize && currRight < arrRightSize) {

        if (arrLeft[currLeft] > arrRight[currRight]) {
            arr[k] = arrRight[currRight++];
            k++;
        }

        else {
            arr[k] = arrLeft[currLeft++];
            k++;
        }

    }

    if(currLeft != arrLeftSize) {
        while (currLeft < arrLeftSize) {
            arr[k++] = arrLeft[currLeft++];
        }
    }

    if(currRight != arrRightSize) {
        while (currRight < arrRightSize) {
            arr[k++] = arrRight[currRight++];
        }
    }

}

void mergeSort (int arr[], int start, int end) {

    if(start == end) {
        return;
    }

    int mid = start + (end - start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, end);


}

int main() {

    clock_t start, end;

    int arr[] = {8, 9, 1, 10, 3, 7, 2};
    int n = 7;

    start = clock();

    mergeSort(arr, 0, n-1);

    end = clock();

    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC );

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}