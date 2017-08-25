#include <stdio.h>

int rec_exp(int, int);

int main()
{
    int a, b; /* a^b */

    printf("\n Enter a and b (a^b)\n");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d^%d equals to %d", a, b, rec_exp(a, b));

    return 0;
}

int rec_exp(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a*rec_exp(a, b - 1);
}
