#include <stdio.h>
int stack[20],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
    top =-1;
    printf("\nEnter the size of Stack, max number is 20\n");
    scanf("%d",&n);
    printf("\n\tStack operations using array are:");
    printf("\n\t1. Push \n\t2. POP \n\t3. Display \n\t4. exit");
    printf("\n\t--------------------------------------------\n");
    do
    {   
        printf("\nEnter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {  
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {    
                display();
                break;
            }
            case 4:
            {
                printf("\nCode Finished");
                break;
            }
            default:
            {
                printf("\nEnter a valid number!");
            }           
        }
    }
    while(choice != 4);
}

void pop(){
    if(top<=-1)
    {
        printf("\nStack is under flow!");
    }
    else
    {
        printf("\nTHe poped element is %d\n",stack[top]);
        top--;
    }        
}
void push(){
    if(top>=n-1)
    {
        printf("\nStack is overflow!");
    }
    else
    {
        printf("\nEnter value to be pushed!: ");
        scanf("%d",&x);
        top++;
        stack[top] = x;
    }
                 
}
void display(){
    if(top>=0)
    {
        printf("\n Element in Stack \n");
        for(i=top; i>=0;i--)
            printf("\n%d", stack[i]);
        printf("\npress NExt choice");
    }
    else
    {
        printf("\nStack is empty");
    }
}
