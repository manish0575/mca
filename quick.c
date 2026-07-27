
#include <stdio.h>

void quickSort(int a[], int low, int high)
{
    int i, j, pivot, temp;

    if(low < high)
    {
        pivot = a[high];
        i = low - 1;

        for(j = low; j < high; j++)
        {
            if(a[j] < pivot)
            {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int p = i + 1;

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int a[] = {12, 20, 22, 16, 25, 18, 8, 10, 6, 15};
    int n = 10, i;

    quickSort(a, 0, n - 1);

    printf("Sorted Array: ");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

