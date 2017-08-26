#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *q;
void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main()
{
    int option, num;

    create_queue(q);

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
                printf("\n Enter the number to insert in the queue");
                scanf("%d", &num);
                q = insert(q, num);
                break;

            case 2:
                q = delete(q);
                break;

            case 3:
                num = peek(q);
                if (num != -1)
                    printf("\n The value at front of the queue is %d", num);
                break;

            case 4:
                q = display(q);
                break;
        }
    }while(option != 5);

    return 0;
}

void create_queue(struct queue *q)
{
    printf("\n breaks in line 71 q->rear = NULL;");
    q->rear = NULL;
    printf("\n breaks in line 73 q->front = NULL;");
    q->front = NULL;
}

struct queue *insert(struct queue *q, int num)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;

    if(q->front == NULL)
        q->front = ptr;
    else
        q->rear->next = ptr;

    q->rear = ptr;

    return q;
}

struct queue *delete(struct queue *q)
{
    struct node *ptr;

    if(q->front == NULL)
        printf("\n UNDERFLOW, THE QUEUE IS EMPTY");
    else
    {
        /*CHECK CODE*/
        ptr = q->front->next;
        free(q->front);
        q->front = ptr;
    }
}

struct queue *display(struct queue *q)
{
    struct node *ptr;

    if(q->front == NULL)
        printf("\n UNDERFLOW, THE QUEUE IS EMPTY");
    else
    {
        ptr = q->front;
        while(ptr != NULL)
        {
            printf("\t %d", ptr->data);
            ptr = ptr->next;
        }
    }
}

int peek(struct queue *q)
{
    return 0;
}

