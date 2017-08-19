#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

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
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main(int argc, char *argv[])
{
    int option;

    do
    {
        printf("\n\n ***** MAIN MENU ******");
        printf("\n 1:   Create a list");
        printf("\n 2:   Display the list");
        printf("\n 3:   Add a node at the beginning");
        printf("\n 4:   Add a node at the end");
        printf("\n 5:   Add a node before a given node");
        printf("\n 6:   Add a node after a given node");
        printf("\n 7:   Delete a node from the beginning");
        printf("\n 8:   Delete a node from the end");
        printf("\n 9:   Delete a node before a given node");
        printf("\n 10:   Delete a node after a given node");
        printf("\n 11:   Delete the entire list");
        printf("\n 12:   EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: start = create_ll(start);
                    printf("\n DOUBLY LINKED LIST CREATED");
                    break;

            case 2: start = display(start);
                    break;

            case 3: start = insert_beg(start);
                    break;

            case 4: start = insert_end(start);
                    break;

            case 5: start = insert_before(start);
                    break;

            case 6: start = insert_after(start);
                    break;

            case 7: start = delete_beg(start);
                    break;

            case 8: start = delete_end(start);
                    break;

            case 9: start = delete_before(start);
                    break;

            case 10: start = delete_after(start);
                    break;

            case 11: start = delete_list(start);
                    printf("\n Linked list deleted");
                    break;
        }
    }while(option != 12);
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
            new_node->prev = NULL;
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;

            while(ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
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
        printf("\n THE DOUBLE LINKED LIST IS EMPTY");
    else
    {
        while(ptr != NULL)
        {
            printf("\t %d", ptr->data);
            ptr = ptr->next;
        }
    }

    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter the node to be inserted at the beginning: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->prev = NULL;

    if (start == NULL)
        new_node->next = NULL;
    else
        new_node->next = start;

    start = new_node;

    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter the node to be inserted at the end: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if(start == NULL)
    {
        new_node->prev = NULL;
        start = new_node;
    }
    else
    {
        ptr = start;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;
        new_node->prev = ptr;
    }

    new_node->next = NULL;

    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;

    printf("\n Enter the data to insert: ");
    scanf("%d", &num);

    printf("\n Enter the data after the inserted ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;

    if(ptr->data != val)
    {
        while((ptr->next)->data != val)
            ptr = ptr->next;

        new_node->prev = ptr;
        new_node->next = ptr->next;

        ptr->next = new_node;
    }
    else
    {
        new_node->next = ptr;
        new_node->prev = NULL;
        start = new_node;
    }

    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;

    printf("\n Enter the data to insert: ");
    scanf("%d", &num);

    printf("\n Enter the data before the inserted: ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;

    while(ptr->data != val)
        ptr = ptr->next;

    if(ptr->next == NULL)
        new_node->next = NULL;
    else
        new_node->next = ptr->next;

    new_node->prev = ptr;
    ptr->next = new_node;

    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;

    ptr = start;
    if(start->next == NULL)
    {
        start = NULL;
        free(ptr);
    }
    else
    {
        start = start->next;
        start->prev = NULL;
        ptr = NULL;
        free(ptr);
    }
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr;

    ptr = start;
    if(start->next == NULL)
    {
        start = NULL;
        free(ptr);
    }
    else
    {
        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->prev->next = NULL;
        free(ptr);
    }

    return start;
}

struct node *delete_before(struct node *start)
{
    return start;
}

struct node *delete_after(struct node *start)
{

    return start;
}

struct node *delete_list(struct node *start)
{
    return start;
}
