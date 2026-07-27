
#include <stdio.h>

int main()
{
    int a = 15265, b = 15, r;
    int mod = 0, assign = 0;

    while (b != 0)
    {
        r = a % b;
        mod++;

        a = b;
        b = r;
        assign += 2;
    }

    printf("GCD = %d\n", a);
    printf("Mod operations = %d\n", mod);
    printf("Assignment operations = %d\n", assign);

    return 0;
}

