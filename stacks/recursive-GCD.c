#include <stdio.h>

int GCD(int ,int);

int main()
{
    int a, b, ans;

    printf("\n Enter the numbers to calculate its GCD (\" Greatest Common Divisor \")\n");
    scanf("%d", &a);
    scanf("%d", &b);

    ans = GCD(a, b);

    printf("\n The GCD of %d and %d is %d", a, b, ans);

    return 0;
}

int GCD(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return GCD(b, a%b);
}
