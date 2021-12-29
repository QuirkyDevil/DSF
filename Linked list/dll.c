/* Insertion at the end of Doubly linked list */
#include <stdio.h>
#include <stdlib.h>

// function declarations
void append(void);
int length();
void display(void);
void deletion(void);
void insertion_beginning(void);
void deletion_beginning(void);
void insertion_pos(int pos);
void deletion_pos(int pos);

// Node structure definition
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// default Head will be NULL
struct node *head = NULL;

int main()
{
    int choice, position;
    while (1)
    {
        printf("\n");
        printf("==========\n");
        printf("DOUBLY LINKED LIST OPERATIONS:\n");
        printf("==========\n\n");

        printf("---- Utils stuff ----\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Insertion at beginning\n");
        printf("4.Deletion at beginning\n");
        printf("5.Insertion at specific Place\n");
        printf("6.Deletion at specific Place\n\n");

        printf("---- Display stuff ----\n");
        printf("7.Display\n");
        printf("8.Length\n");
        printf("9.Exit\n");

        printf("==========\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        printf("==========\n\n\n");
        switch (choice)
        {
        case 1:
            append();
            break;
        case 2:
            deletion();
            break;
        case 3:
            insertion_beginning();
            break;
        case 4:
            deletion_beginning();
            break;
        case 5:
            printf("Enter a position: ");
            scanf("%d", &position);
            insertion_pos(position);
            break;
        case 6:
            printf("Enter a position: ");
            scanf("%d", &position);
            deletion_pos(position);
            break;
        case 7:
            display();
            break;
        case 8:
            length();
            break;
        case 9:
            printf("Session Ended!");
            exit(1);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        struct node *p;
        p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
    }
}

void insertion_beginning()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertion_pos(int pos)
{
    struct node *p = head;
    struct node *temp, *p2;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    while (pos != 1)
    {
        p = p->next;
        pos--;
    }
    p2 = p->next;
    p->next = temp;
    p2->prev = temp;
    temp->next = p2;
    temp->prev = p;
}

void deletion()
{
    if (head == NULL)
    {
        printf("List is Alredy Empty! \n");
    }
    else
    {
        struct node *temp = head;
        struct node *p;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        p = temp->prev;
        p->next = NULL;
        free(temp);
    }
}

void deletion_beginning()
{
    if (head == NULL)
    {
        printf("List is Empty! \n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
        head->prev = NULL;
    }
}

void deletion_pos(int pos)
{
    struct node *current = head;
    struct node *previous = head;
    if (head == NULL)
    {
        printf("List is Empty! \n");
    }
    else
    {
        while (pos != 1)
        {
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

void display()
{
    int a = 1;
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("Empty BrB \n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Element at %d place is: %d \n", a, temp->data);
            temp = temp->next;
            a++;
        }
        printf("\n");
    }
}

int length()
{
    int x = 0;
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("Empty BrB \n");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
            x++;
        }
        printf("Length of Singly Linked list is: %d\n", x);
    }
}