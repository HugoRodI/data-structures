#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
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
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

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
        printf("\n 9:   Delete a given node");
        printf("\n 10:   Delete a node after a given node");
        printf("\n 11:   Delete the entire list");
        printf("\n 12:   Sort the list");
        printf("\n 13:   EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: start = create_ll(start);
                    printf("\n Linked list created!");
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

            case 9: start = delete_node(start);
                    break;

            case 10: start = delete_after(start);
                    break;

            case 11: start = delete_list(start);
                    printf("\n Linked list deleted");
                    break;

            case 12: start = sort_list(start);
                    break;
        }
    }while(option != 13);
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

        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
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

    while(ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }

    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;

    printf("\n Enter the number to be inserted at the beginning: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;

    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\n Enter the number to be inserted at the end: ");
    scanf("%d", &num);

    ptr = start;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if (ptr == NULL)
    {
        start = new_node;
    }
    else
    {
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
    new_node->next = NULL;
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;

    printf("\n Enter the number to be inserted: ");
    scanf("%d", &num);

    printf("\n Enter the number after the one to be inserted: ");
    scanf("%d", &val);

    ptr = start;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if ((ptr->next) == NULL)
    {
        new_node->next = ptr;
        start = new_node;
    }
    else
    {
        while((ptr->next)->data != val)
            ptr = ptr->next;

        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;

    printf("\n Enter the number to be inserted: ");
    scanf("%d", &num);

    printf("\n Enter the number after the one to be inserted: ");
    scanf("%d", &val);

    ptr = start;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    while(ptr->data != val)
        ptr = ptr->next;

    if (ptr->next != NULL)
        new_node->next = ptr->next;
    else
        new_node->next = NULL;

    ptr->next = new_node;

    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;

    ptr = start;
    start = start->next;
    free(ptr);

    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;

    ptr = start;

    if (ptr->next == NULL)
    {
        start = start->next;
        free(ptr);
    }
    else
    {
        while(ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
    return start;
}

struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;

    printf("\n Enter the value to delete: ");
    scanf("%d", &val);

    ptr = start;
    /*if its the first node*/
    if (ptr->data == val)
        return delete_beg(start);

    /*if its the last node*/
    while((ptr->next) != NULL)
        ptr = ptr->next;

    if (ptr->data == val)
        return delete_end(start);

    /*if its between the first and last node*/
    ptr = start;

    while((ptr->next)->data != val)
        ptr = ptr->next;

    preptr = ptr->next;
    ptr->next = (ptr->next)->next;
    preptr->next = NULL;
    free(preptr);
    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    int val;

    printf("\n Enter the value to delete: ");
    scanf("%d", &val);

    ptr = start;

    if ((ptr->next)->next == NULL)
    {
        temp = ptr->next;
        ptr->next = NULL;
    }
    else
    {
        while((ptr->next)->data != val)
            ptr = ptr->next;

        temp = ptr->next;
        ptr->next = (ptr->next)->next;
    }

    free(temp);

    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;

    ptr = start;
    while(ptr != NULL)
    {
        start = start->next;
        free(ptr);
        ptr = start;
    }

    return start;
}

struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;

    ptr1 = start;

    while(ptr1->next != NULL)
    {
        ptr2 = ptr1->next;

        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr2->data;
                ptr2->data = ptr1->data;
                ptr1->data = temp;
            }

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return start;
}

