#include <stdio.h>

#define SIZE 5

int st[SIZE];
int top = -1;
void push(int);
int pop();

int main()
{
    int inversed[SIZE], i;

    for (i = 0; i < SIZE; ++i)
    {
        printf("\n Enter the element %d of the array: ", i + 1);
        scanf("%d", &st[i]);
        push(st[i]);
    }

    printf("\n The input array is: ");

    for (i = 0; i < SIZE; ++i)
        printf("\n %d", st[i]);

    for (i = 0; i < SIZE; ++i)
        inversed[i] = pop();

    printf("\n The inversed array is: ");

    for (i = 0; i < SIZE; ++i)
        printf("\n %d", inversed[i]);

    return 0;
}

void push(int val)
{
    st[++top] = val;
}

int pop()
{
    return st[top--];
}
