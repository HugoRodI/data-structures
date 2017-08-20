#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: start = create_ll(start);
                    printf("\n CIRCULAR DOUBLY LINKED LIST CREATED");
                    break;

            case 2: start = display(start);
                    break;

            case 3: start = insert_beg(start);
                    break;

            case 4: start = insert_end(start);
                    break;

            case 5: start = delete_beg(start);
                    break;

            case 6: start = delete_end(start);
                    break;

            case 7: start = delete_node(start);
                    break;

            case 8: start = delete_list(start);
                    printf("\n CIRCULAR DOUBLY LINKED LIST DELETED");
                    break;
        }
    }while(option != 9);

    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);

    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if(start == NULL)
        {
            new_node->next = new_node;
            new_node->prev = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;

            while(ptr->next != start)
                ptr = ptr->next;

            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = start;
            start->prev = new_node;
        }

        printf("\n Enter the data: ");
        scanf("%d", &num);
    }

    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;

    if(start == NULL)
        printf("\n The Circular Doubly Linked List is empty!");
    else
    {
        ptr = start;

        while(ptr->next != start)
        {
            printf("\t %d", ptr->data);
            ptr = ptr->next;
        }

        printf("\t %d", ptr->data);
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter the value to insert at the beginning: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (start == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        start = new_node;
    }
    else
    {
        ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;

        new_node->prev = ptr;
        new_node->next = start;
        ptr->next = new_node;
        start->prev = new_node;
        start = new_node;
    }
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter the value to insert at the end: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if(start == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        start = new_node;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
            ptr = ptr->next;

        new_node->prev = ptr;
        new_node->next = start;
        ptr->next = new_node;
        start->prev = new_node;
    }

    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *new_node, *ptr;


    if (start->next != start)
    {
        ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;

        ptr->next = start->next;
        start->next->prev = ptr;
        free(start);
        start = ptr->next;
    }
    else
    {
        free(start);
        start = NULL;
    }
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *new_node, *ptr;

    if (start->next != start)
    {
        ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;

        ptr->prev->next = start;
        start->prev = ptr->prev;
        free(ptr);
    }
    else
    {
        free(start);
        start = NULL;
    }
    return start;
}

struct node *delete_node(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter the node after which delete");
    scanf("%d", &num);

    ptr = start;
    while (ptr->data != num)
        ptr = ptr->next;

    /*if theres only one node*/
    if (ptr->next == ptr)
    {
        free (start);
        start = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;

    while(start != NULL)
    {
        if(start->next != start)
        {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;

            ptr->next = start->next;
            start->next->prev = ptr;
            free(start);
            start = ptr->next;
        }
        else
        {
            free(start);
            start = NULL;
        }
    }

    return start;
}
