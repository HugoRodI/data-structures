#include <stdio.h>

int factorial(int);

int main()
{
    int num, ans;

    printf("\n Enter the number to calculate its factorial: ");
    scanf("%d", &num);

    ans = factorial(num);
    printf("\n The factorial of %d is %d\n", num, ans);

    return 0;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n*factorial(n-1);
}
