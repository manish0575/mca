#include <stdio.h>

int binarySearch(int a[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == key)
        return mid;
    else if (key < a[mid])
        return binarySearch(a, low, mid - 1, key);
    else
        return binarySearch(a, mid + 1, high, key);
}

int main()
{
    int a[] = {10, 35, 40, 45, 50, 55, 60, 65, 70, 100};
    int n = 10, key = 100;

    int result = binarySearch(a, 0, n - 1, key);

    if (result != -1)
        printf("100 found at position %d", result);
    else
        printf("100 not found");

    return 0;
}

