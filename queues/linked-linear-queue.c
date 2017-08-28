#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
}*front, *rear;

void create_queue();
struct node *insert(int);
struct node *delete();
struct node *display();
int peek();

int main()
{
    int option, num;

    create_queue();

    do
    {
        printf("\n ***** main menu *****");
        printf("\n 1. Insert queue");
        printf("\n 2. Delete element");
        printf("\n 3. Peek");;
        printf("\n 4. Display");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n Enter the number to insert in the queue: ");
                scanf("%d", &num);
                front = insert(num);
                break;

            case 2:
                front  = delete();
                break;

            case 3:
                num = peek();
                if (num != -1)
                    printf("\n The value at front of the queue is %d", num);
                break;

            case 4:
                front = display();
                break;
        }
    }while(option != 5);

    return 0;
}

void create_queue()
{
    rear = NULL;
    front = NULL;
}

struct node *insert(int num)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;

    if(front == NULL)
        front = ptr;
    else
        rear->next = ptr;

    rear = ptr;

    return front;
}

struct node *delete()
{
    struct node *ptr;

    if(front == NULL)
        printf("\n THE QUEUE IS EMPTY");
    else
    {
      /*  CHECK CODE */
        ptr = front;
        front = front->next;
        free(ptr);
    }

    return front;
}

struct node *display()
{
    struct node *ptr;

    if(front == NULL)
        printf("\n THE QUEUE IS EMPTY");
    else
    {
        ptr = front;
        while(ptr != NULL)
        {
            printf("\t %d", ptr->data);
            ptr = ptr->next;
        }
    }

    return front;
}

int peek()
{
    return 0;
}

