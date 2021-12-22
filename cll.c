/*  Circular linked list */
#include <stdio.h>
#include <stdlib.h>

// function declarations
int length();
void append(void);
void display(void);
void insertion_beginning(void);

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
            printf("Session Ended!");
            break;
        case 3:
            insertion_beginning();
            break;
        case 4:
            printf("Session Ended!");
            break;
        case 5:
            printf("Session Ended!");
            break;
        case 6:
            printf("Session Ended!");
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
void append(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &temp->data);

    if(head == NULL){
        head = temp;
        temp->link = head;
    }
    else{
        struct node *p;
        p = head;
        while(p->link != head){
            p = p->link;
        }
        p->link = temp;
        temp->link = head;
    }
}

void insertion_beginning()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("==========\n");
    printf("Enter data: ");
    scanf("%d", &temp->data);   

    if(head == NULL){
        temp = head;
        temp->link = head;
    }
    else{
        struct node *p;
        p = head;
        while(p->link != head){
            p = p->link;
        }
        temp->link = head;
        head = temp;
        p->link = head;
    }
    printf("==========\n");
}

void display(){
    struct node *temp;
    int a = 1;
    temp = head;
    if(temp == NULL){
        printf("empty Brb");
    }
    else{
        printf("================\n");
        while (temp->link != head){
            printf("Element at pos %d is %d\n",a, temp->data);
            temp = temp->link;
            a++;
        }
        printf("Element at pos %d is %d\n", a, temp->data);
        printf("================\n");
    }
}

int length(){
    struct node *temp;
    temp = head;
    int a = 0;
    do{
        a++;
        temp = temp->link;
    }while(temp != head);
    printf("Length of Circular Linked list is %d\n", a);
}