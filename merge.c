
#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[20];

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        int i;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);

        printf("Step: ");
        for(i = low; i <= high; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}

int main()
{
    int a[] = {200, 150, 50, 100, 75, 25, 10, 5};
    int n = 8;
    int i;

    printf("Original: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nMerge Sort Steps:\n");

    mergeSort(a, 0, n - 1);

    printf("\nSorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

