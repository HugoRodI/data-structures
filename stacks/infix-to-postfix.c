#include <stdio.h>
#include <conio.h>
#include <string.h>

int top = -1;
int st[6];
void push(char);
char pop();

int main()
{
    char infix[30], postfix[30], op, index = 0;
    int i = 0;


    printf("\n Enter the infix expression: \n");
    scanf("%s", &infix);

    for ( ; i < strlen(infix); ++i )
        if (infix[i] == '+' || infix[i] == '-')
            push(infix[i]);

    for (i = 0; i < strlen(infix); ++i )
        if (infix[i] == '*' || infix[i] == '/')
            push(infix[i]);

    op = pop();

    i = 0;
    while (infix[i] != op)
        i++;

    postfix[index++] = infix[i - 1];
    postfix[index++] = infix[i + 1];
    postfix[index++] = op;

    printf("%s", postfix);

    i--;

    while(top >= 0)
    {
        op = pop();
        i -= 2;
        postfix[index++] = infix[i];
        postfix[index++] = op;
    }

    postfix[index] = '\0';

    printf("\n The postfix expression is: %s", postfix);

    return 0;
}

void push(char val)
{
    st[++top] = val;
}

char pop()
{
    return st[top--];
}
