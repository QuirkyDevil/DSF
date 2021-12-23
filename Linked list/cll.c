/*  Circular linked list */
#include <stdio.h>
#include <stdlib.h>

// function declarations
int length(void);
void display(void);
void append(void);
void add_after(void);
void insertion_beginning(void);
void deletion(void);

// NOde structure definition
struct node
{
    int data;
    struct node *next;
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
        printf("3.Deletion at beginning\n");
        printf("4.Insertion at specific Place\n");
        printf("5.Deletion at specific Place\n\n");

        printf("---- Display stuff ----\n");
        printf("6.Display\n");
        printf("7.Length\n");
        printf("8.Exit\n");

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
            printf("Session Ended!");
            break;
        case 4:
            add_after();
            break;
        case 5:
            printf("Session Ended!");
        case 6:
            display();
            break;
        case 7:
            length();
            break;
        case 8:
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

    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        struct node *p;
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
    }
}

void deletion()
{
    struct node *temp;
    temp = head->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    head = temp->next;
}

void insertion_beginning()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("==========\n");
    printf("Enter data: ");
    scanf("%d", &temp->data);

    if (head == NULL)
    {
        temp = head;
        temp->next = head;
    }
    else
    {
        struct node *p;
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        temp->next = head;
        head = temp;
        p->next = head;
    }
    printf("==========\n");
}

void add_after()
{
    struct node *temp, *p;
    int location, i = 1;
    int len = length();
    printf("Enter Location: ");
    scanf("%d", &location);

    if (location > len)
    {
        printf("Location is out of bounds");
    }
    else
    {
        p = head;
        while (i < location)
        {
            p = p->next;
            i++;
        }
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->next = p->next;
        p->next = temp;
    }
}

void display()
{
    struct node *temp;
    int a = 1;
    temp = head;
    if (temp == NULL)
    {
        printf("empty Brb");
    }
    else
    {
        printf("================\n");
        while (temp->next != head)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
            a++;
        }
        printf("%d\n", temp->data);
        printf("================\n");
    }
}

int length()
{
    struct node *temp;
    temp = head;
    int a = 0;
    do
    {
        a++;
        temp = temp->next;
    } while (temp != head);
    printf("Length of Circular Linked list is %d\n", a);
    return a;
}