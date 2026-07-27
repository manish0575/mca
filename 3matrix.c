
#include <stdio.h>

int main()
{
    int A[3][3], B[3][3], C[3][3] = {0};
    int i, j, k;
    int outer = 0, inner = 0;
    int add = 0, mul = 0;

    printf("Enter Matrix A:\n");
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &B[i][j]);

    for(i = 0; i < 3; i++)
    {
        outer++;

        for(j = 0; j < 3; j++)
        {
            for(k = 0; k < 3; k++)
            {
                C[i][j] += A[i][k] * B[k][j];

                mul++;
                inner++;

                if(k > 0)
                    add++;
            }
        }
    }

    printf("\nResult Matrix:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    printf("\nOutermost loop runs = %d times", outer);
    printf("\nInnermost loop runs = %d times", inner);
    printf("\nTotal additions = %d", add);
    printf("\nTotal multiplications = %d\n", mul);

    return 0;
}

