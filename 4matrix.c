
#include <stdio.h>

int main()
{
    int A[4][4], B[4][4], C[4][4] = {0};
    int i, j, k;
    int outer = 0, inner = 0;
    int mul = 0, add = 0;

    printf("Enter Matrix A:\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            scanf("%d", &B[i][j]);

    for(i = 0; i < 4; i++)
    {
        outer++;

        for(j = 0; j < 4; j++)
        {
            for(k = 0; k < 4; k++)
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
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    printf("\nOutermost loop = %d times", outer);
    printf("\nInnermost loop = %d times", inner);
    printf("\nMultiplications = %d", mul);
    printf("\nAdditions = %d\n", add);

    return 0;
}

