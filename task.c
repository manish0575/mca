
#include <stdio.h>

int main()
{
    int job[] = {1, 2, 3, 4};
    int time[] = {5, 10, 7, 8};
    int i, j, temp;
    int total = 0, waiting = 0;


    for(i = 0; i < 4; i++)
    {
        for(j = i + 1; j < 4; j++)
        {
            if(time[i] > time[j])
            {
                temp = time[i];
                time[i] = time[j];
                time[j] = temp;

                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    printf("Job order: ");

    for(i = 0; i < 4; i++)
    {
        printf("J%d ", job[i]);

        waiting += time[i];
        total += waiting;
    }

    printf("\nTotal time = %d", total);
    printf("\nAverage time = %.2f\n", total / 4.0); // if 6 job to change 6.0

    return 0;
}

