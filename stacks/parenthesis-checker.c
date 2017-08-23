#include <stdio.h>
#include <string.h>

int top = -1;
char st[5];
void push(char);
char pop();

int main()
{
    char temp, exp[20];
    int valid, i = 0;

    valid = 1;

    printf("\n Enter an expression to check it's parenthesis validity:\n\n");
    scanf("%s", &exp);

    for ( ; i < strlen(exp); ++i)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);

        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            temp = pop();

            if (exp[i] == ')' && (temp == '[' || temp == '{'))
                valid = 0;

            if (exp[i] == ']' && (temp == '(' || temp == '{'))
                valid = 0;

            if (exp[i] == '}' && (temp == '(' || temp == '['))
                valid = 0;

        }

    }

    if (valid)
        printf("\n Valid expression");
    else
        printf("\n Invalid expression");

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
