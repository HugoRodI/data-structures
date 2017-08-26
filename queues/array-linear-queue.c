#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;
void insert(void);
int delete(void);
int peek(void);
void display(void);

int main()
{
    int option, num;

    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element: ");
        printf("\n 2. Delete an element: ");
        printf("\n 3. Peek an element");
        printf("\n 4. Display all elements");
        printf("\n 5. EXIT");
        printf("\n Enter an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                insert();
                break;

            case 2:
                num = delete();
                if (num != -1)
                    printf("\n The number deleted is %d \n", num);
                break;

            case 3:
                num = peek();
                if (num != -1)
                    printf("\n The FIFO value in queue is: %d \n", num);
                break;

            case 4:
                display();
                break;

        }

    }while(option != 5);

    return 0;
}

void insert()
{
    int num;

    printf("\n Enter the number to be inserted: ");
    scanf("%d", &num);

    if (rear == MAX - 1)
        printf("\n OVERFLOW");
    else if(front == - 1 && rear == -1)
        front = rear = 0;
    else
        ++rear;

    queue[rear] = num;
}

int delete()
{
    int val;

    if (front == -1 || front > rear)
    {
        printf("\n UNDERFLOW\n");
        return -1;
    }
    else
    {
        val = queue[front++];

        if(front > rear)
            front = rear = -1;

        return val;
    }

}

int peek()
{
    if(front == -1 || front > rear)
        printf("\n THE QUEUE IS EMPTY \n");
    else
        return queue[front];

    return -1;
}

void display()
{
    int i;
    printf("\n");

    if(front == -1 || front > rear)
        printf("\n THE QUEUE IS EMPTY");
    else
        for ( i = front; i <= rear; ++i )
            printf("\t %d", queue[i]);

    printf("\n");
}
