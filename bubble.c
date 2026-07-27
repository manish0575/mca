
#include <stdio.h>

int main()
{
    int a[] = {55, 25, 15, 40, 60, 35, 17, 65, 75, 10};
    int n = 10;
    int i, j, temp;
    int exchange = 0, comparison = 0;
    int outer = 0, inner = 0;

    for(i = 0; i < n - 1; i++)
    {
        outer++;

        for(j = 0; j < n - i - 1; j++)
        {
            inner++;
            comparison++;

            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                exchange++;
            }
        }
    }

    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nExchange operations = %d", exchange);
    printf("\nComparison operations = %d", comparison);
    printf("\nOuter loop iterations = %d", outer);
    printf("\nInner loop iterations = %d\n", inner);

    return 0;
}
