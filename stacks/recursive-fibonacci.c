#include <stdio.h>

int fib(int);

int main()
{
    int num;

    printf("\n Enter the number of digits in Fibonacci sequence: ");
    scanf("%d", &num);

    printf("\n");

    for (int i = 0; i < num; i++)
        printf("\t %d", fib(i));


    return 0;
}

int fib(int index)
{
    if (index == 0)
        return 0;
    else if (index == 1)
        return 1;
    else
        return (fib(index - 1) + fib(index -2));
}
