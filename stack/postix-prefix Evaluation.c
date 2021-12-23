#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100
char stack_ch[SIZE];
int stack[20];
int top = -1;
#define MAX 50
char infix[MAX], prefix[MAX];

void push_ch(char item)
{
    if (top >= SIZE - 1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top = top + 1;
        stack_ch[top] = item;
    }
}
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return stack[top--];
}
void EvalPostfix(char exp[])
{
    char *e;
    int n1, n2, n3, num, check;
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();

            switch (*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                if (n1 == 0)
                {
                    printf("\nError performing division(divide by zero)");
                    break;
                }
                else
                {
                    n3 = n2 / n1;
                    break;
                }
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nValue of expression  =  %d\n\n", pop());
}
long int eval_pre(char prefix[])
{
    long int a, b, temp, result;
    int i;

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        if (prefix[i] <= '9' && prefix[i] >= '0')
            push(prefix[i] - 48);
        else
        {
            b = pop();
            a = pop();
            switch (prefix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = pow(b, a);
            }
            push(temp);
        }
    }
    result = pop();
    return result;
} /*End of eval_pre */

int main()
{
    char infix[SIZE], postfix[SIZE];
    int i, opt;
    char cont;
    char exp[20];
    long int value;
    do
    {

        printf("\n\t\tMENU\n");
        printf("\t\t~~~~\n\n");
        printf("1.Postfix Evaluation\n");
        printf("2.Prefix Evaluation\n");
        printf("Enter your choice:");
        scanf("%d", &opt);
        getchar();
        switch (opt)
        {
        case 1:
            printf(" \nEnter postfix expression : ");
            scanf("%s", exp);
            /* call function to evaluate postfix expression */

            EvalPostfix(exp);
            break;
        case 2:
            printf("\nEnter Prefix expression : ");
            fgets(infix, SIZE, stdin);
            value = eval_pre(infix);
            printf("Value of expression : %d\n", value);
            break;
        default:
            printf("Invalid Choice");
        }
        printf("\nDo you want to continue ? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
    return 0;
}