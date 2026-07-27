
#include <stdio.h>

int main()
{
    int p[] = {15, 5, 20, 8, 7, 20, 6};
    int w[] = {3, 4, 6, 8, 2, 2, 3};
    int n = 7, cap = 18;
    int i, j, temp;
    float ratio[7], profit = 0;


    for(i = 0; i < n; i++)
        ratio[i] = (float)p[i] / w[i];


    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = p[i]; p[i] = p[j]; p[j] = temp;
                temp = w[i]; w[i] = w[j]; w[j] = temp;

                float t = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t;
            }
        }
    }


    for(i = 0; i < n; i++)
    {
        if(w[i] <= cap)
        {
            cap -= w[i];
            profit += p[i];
        }
        else
        {
            profit += ratio[i] * cap;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", profit);

    return 0;
}
