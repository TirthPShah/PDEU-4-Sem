#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        int currKey = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > currKey) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = currKey;

    }

}

int main() {

    clock_t start, end;

    int arr[] = {8, 9, 1, 10, 3, 7, 2};
    int n = 7;

    start = clock();

    insertionSort(arr, n);

    end = clock();

    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}