/* Insertion at the end of singly linked list */
#include <stdio.h>
#include <stdlib.h>

void append(void);
void display(void);

struct node{
    int data;
    struct node *link;
};

struct node *head = NULL;

int main(){
    int choice;
    while (1){
        printf("==========\n");
        printf("Enter a Choice:\n");
        printf("1.Append\n");
        printf("2.Display\n");
        printf("3.Exit\n");
        printf("==========\n");

        printf("Enter a choice: ");
        scanf("%d", &choice);
        printf("==========\n");
        switch (choice)
        {
        case 1:
            append();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(1);
        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}

void append(){
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

void display(){
    int a= 1;
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("Empty Brb");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Element at %d place is: %d \n",a, temp->data);
            temp = temp->link;
            a++;
        }
        printf("\n");
    }
}