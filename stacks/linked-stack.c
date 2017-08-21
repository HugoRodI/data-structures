#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);
int peek(struct stack *);

int main()
{
    int val, option;

    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1: PUSH");
        printf("\n 2: POP");
        printf("\n 3: PEEK");
        printf("\n 4: DISPLAY");
        printf("\n 5: EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n Enter the value to be pushed on the stack: ");
                scanf("%d", &val);
                top = push(top, val);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                val = peek(top);
                break;

            case 4:
                top = display(top);
                break;
        }
    }while(option != 5);

    return 0;
}

struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;

    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;

    ptr->next = NULL;
    if (top != NULL)
        ptr->next = top;

    top = ptr;

    return top;
}

struct stack *pop(struct stack *top)
{
    struct stack *ptr;

    ptr = top;

    if (ptr == NULL)
        printf("\n The stack is empty");
    else
    {
            top = top->next;
            free(ptr);
    }
    return top;
}

int peek(struct stack *top)
{
    struct stack *ptr;

    ptr = top;

    if (ptr == NULL)
    {
        printf("\n The stack is empty");
        return -1;
    }
    else
    {
        printf("\n The value at the top of the stack is %d", top->data);
        return top->data;
    }
}

struct stack *display(struct stack *top)
{
    struct stack *ptr;

    ptr = top;

    if (ptr == NULL)
        printf("\n The stack is empty");

    while(ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }

    return top;
}
