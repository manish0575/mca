#include <stdio.h>

void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    int j;
    for(j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

int main() {
    int myArray[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int e = sizeof(myArray) / sizeof(myArray[0]);
    int s = 0;
    int i;
    quicksort(myArray, s, e - 1);

    printf("Sorted array: ");
    for(i = 0; i < e; i++) {
        printf("%d ", myArray[i]);
    }
    return 0;
}
//C