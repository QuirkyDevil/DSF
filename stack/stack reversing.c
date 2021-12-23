#include <stdio.h>
#include <string.h>

void push(void);
void pop(void);


int top=-1, x, n;
char stack[10];
int main()
{
    int str[10];

    
    int i;
    printf("\nEnter the size of Stack, max number is 20\n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        push();
    
    printf("\n=====================================================================");
    for(i=0;i<n;i++)
        pop();

}
void pop(){
    if(top<=-1)
    {
        printf("\nStack is under flow!");
    }
    else
    {
        printf("\nAfter revesring element is %d\n",stack[top]);
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