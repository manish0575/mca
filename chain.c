#include <stdio.h>
#include <limits.h>

#define MAX 10

int m[MAX][MAX];
int s[MAX][MAX];

// Function to print optimal parenthesization
void printOptimalParenthesis(int i, int j)
{
    if (i == j)
    {
        printf("%c", 'A' + i - 1);
        return;
    }

    printf("(");
    printOptimalParenthesis(i, s[i][j]);
    printOptimalParenthesis(s[i][j] + 1, j);
    printf(")");
}

// Matrix Chain Multiplication
void matrixChainOrder(int p[], int n)
{
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications = %d\n", m[1][n - 1]);

    printf("Optimal Parenthesization = ");
    printOptimalParenthesis(1, n - 1);
    printf("\n");
}

int main()
{
    // Dimensions of matrices:
    // A=10x4, B=4x5, C=5x20, D=20x2, E=2x50
    int p[] = {10, 4, 5, 20, 2, 50};

    int n = sizeof(p) / sizeof(p[0]);

    matrixChainOrder(p, n);

    return 0;
}