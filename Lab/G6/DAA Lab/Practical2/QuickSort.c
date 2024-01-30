#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int getPartition(int arr[], int s, int e) {

    int i = s;
    int pivot = arr[e];

    for (int k = s; k <= e-1; k++) {
        if (arr[k] < pivot) {
            swap(&arr[k], &arr[i]);
            i++;
        }
    }

    swap(&arr[i], &arr[e]);

    return i;
}

void quickSort(int arr[], int s, int e) {

    if(s >= e) {
        return ;
    }

    int pi = getPartition(arr, s, e);

    quickSort(arr, s, pi-1);
    quickSort(arr, pi+1, e);

}

int main() {

    clock_t start, end;

    int arr[] = {8, 9, 1, 10, 3, 7, 2};
    int n = 7;

    start = clock();

    quickSort(arr, 0, n-1);

    end = clock();

    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC );

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}