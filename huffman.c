
#include <stdio.h>

int main()
{
    int f[] = {10, 7, 15, 8, 10, 5, 2};
    int n = 7, i, j, temp;
    int total = 0, sum;

    // Sort frequencies
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(f[i] > f[j])
            {
                temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }

    printf("Huffman Process:\n");

    while(n > 1)
    {
        sum = f[0] + f[1];
        total += sum;

        printf("%d + %d = %d\n", f[0], f[1], sum);

        // Remove first two and insert sum
        f[1] = sum;

        for(i = 0; i < n-1; i++)
            f[i] = f[i+1];

        n--;

        // Sort again
        for(i = 0; i < n-1; i++)
            for(j = i+1; j < n; j++)
                if(f[i] > f[j])
                {
                    temp = f[i];
                    f[i] = f[j];
                    f[j] = temp;
                }
    }

    printf("\nTotal Huffman Cost = %d bits", total);

    return 0;
}
