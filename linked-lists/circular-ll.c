#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
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
        printf("\n 7: Delete a node after a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: start = create_cll(start);
                    printf("\n CIRCULAR LINKED LIST CREATED");
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

            case 7: start = delete_after(start);
                    break;

            case 8: start = delete_list(start);
                    printf("\n CIRCULAR LINKED LIST DELETED");
                    break;
        }
    }while(option != 9);

    return 0;
}

struct node *create_cll(struct node *start)
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
        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != start)
                ptr = ptr->next;

            ptr->next = new_node;
            new_node->next = start;
        }

        printf("\n Enter the data: ");
        scanf("%d", &num);
    }

    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;

    ptr = start;

    if (start == NULL)
    {
        printf("\n The Circular Linked List is empty!!!");
    }
    else
    {
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
    ptr = start;

    if (start != NULL)
    {
        while(ptr->next != start)
            ptr = ptr->next;

        ptr->next = new_node;
        new_node->next = start;
        start = new_node;
    }
    else
    {
        new_node->next = new_node;
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

    ptr = start;

    if (start != NULL)
    {
        while(ptr->next != start)
            ptr = ptr->next;

        ptr->next = new_node;
        new_node->next = start;
    }
    else
    {
        new_node->next = new_node;
        start = new_node;
    }

    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *new_node, *ptr;

    if(start->next != start)
    {
        ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;

        ptr->next = start->next;
        free(start);
        start = ptr->next;
    }
    else
    {
        start->next = NULL;
        start = NULL;
        free(start);
    }

    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *new_node, *ptr, *temp;

    if(start->next != start)
    {
        ptr = start;
        while ((ptr->next)->next != start)
            ptr = ptr->next;

        temp = ptr->next;
        ptr->next = start;
        temp = NULL;
        free(temp);
    }
    else
    {
        start->next = NULL;
        start = NULL;
        free(start);
    }

    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *new_node, *ptr, *tmp;
    int num;

    printf("\n Enter the node after which delete");
    scanf("%d", &num);

    ptr = start;

    while(ptr->data != num)
        ptr = ptr->next;

    tmp = ptr->next;
    ptr->next = (ptr->next)->next;
    tmp = NULL;
    free(tmp);

    start = ptr->next;
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;

    ptr = start;

    while(ptr->next != start)
        start = delete_end(start);

    start = NULL;
    free(ptr);

    return start;
}
