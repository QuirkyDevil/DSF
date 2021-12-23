/* Insertion at the end of singly linked list */
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

// NOde structure definition
struct node
{
    int data;
    struct node *link;
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
        printf("SINGLY LINKED LIST OPERATIONS:\n");
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

    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *p;
        p = head;

        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
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
        struct node *p = head;
        while (temp->link != NULL)
        {
            p = temp;
            temp = temp->link;
        }
        p->link = NULL;
        free(temp);
        temp = NULL; // NO need tho
    }
}

void insertion_beginning()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    temp->link = NULL;
    temp->link = head;
    head = temp;
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
        head = head->link;
        free(temp);
        temp = NULL;
    }
}

void insertion_pos(int pos)
{
    struct node *p = head;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    while (pos != 1)
    {
        p = p->link;
        pos--;
    }
    temp->link = p->link;
    p->link = temp;
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
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
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
            temp = temp->link;
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
            temp = temp->link;
            x++;
        }
        printf("Length of Singly Linked list is: %d\n", x);
    }
}
