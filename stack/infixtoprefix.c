#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100
char stack_ch[SIZE];
int stack[20];
int top = -1;
#define BLANK ' '
#define MAX 50
char infix[MAX], prefix[MAX];

/* define push operation*/

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

/* define pop operation */
char pop_ch()
{
    char item;

    if (top < 0)
    {
        printf("stack under flow: invalid infix expression");
        getchar();
        exit(1);
    }
    else
    {
        item = stack_ch[top];
        top = top - 1;
        return (item);
    }
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
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

int precedence(char symbol)
{
    if (symbol == '^') /* exponent operator, highest precedence*/
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-') /* lowest precedence */
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

/* This function returns the priority of the operator */
int priority(char symbol)
{
    switch (symbol)
    {
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    } /*End of switch*/
} /*End of priority()*/

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int white_space(char symbol)
{
    if (symbol == BLANK || symbol == '\t' || symbol == '\0')
        return 1;
    else
        return 0;
} /*End of white_space()*/

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;

    push_ch('(');           /* push '(' onto stack */
    strcat(infix_exp, ")"); /* add ')' to infix expression */

    i = 0;
    j = 0;
    item = infix_exp[i]; /* initialize before loop*/

    while (item != '\0')
    {
        if (item == '(')
        {
            push_ch(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            x = pop_ch();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop_ch();
            }
            push_ch(x);

            push_ch(item);
        }
        else if (item == ')')
        {
            x = pop_ch();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop_ch();
            }
        }
        else
        { /* if current symbol is neither operand not '(' nor ')' and nor
            operator */
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;

        item = infix_exp[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }

    postfix_exp[j] = '\0';
}

void infix_to_prefix(char infix[])
{
    int i, j, p, n;
    char next;
    char symbol;
    char temp;
    n = strlen(infix);
    p = 0;

    for (i = n - 1; i >= 0; i--)
    {
        symbol = infix[i];
        if (!white_space(symbol))
        {
            switch (symbol)
            {
            case ')':
                push_ch(symbol);
                break;
            case '(':
                while ((next = pop_ch()) != ')')
                    prefix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!isempty() && priority(stack[top]) > priority(symbol))
                    prefix[p++] = pop_ch();
                push_ch(symbol);
                break;
            default: /*if an operand comes*/
                prefix[p++] = symbol;
            }
        }
    }
    while (!isempty())
        prefix[p++] = pop_ch();
    prefix[p] = '\0'; /*End prefix with'\0' to make it a string*/

    for (i = 0, j = p - 1; i < j; i++, j--)
    {
        temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
} /*End of infix_to_prefix()*/

int main()
{
    char infix[SIZE], postfix[SIZE];
    int i, opt;
    char cont;
    do
    {

        printf("\nMENU\n");
        printf("1.Infix to Postfix\n");
        printf("2.Infix to Prefix\n");
        printf("Enter your choice:");
        scanf("%d", &opt);
        getchar();
        switch (opt)
        {
        case 1:
            printf("\nASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
            printf("\nEnter Infix expression : ");
            fgets(infix, SIZE, stdin);

            InfixToPostfix(infix, postfix); /* call to convert */
            printf("Postfix Expression: ");
            puts(postfix);
            break; /* print postfix expression */

        case 2:
            printf("\nASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
            printf("\nEnter Infix expression : ");
            fgets(infix, SIZE, stdin);
            infix_to_prefix(infix);
            printf("Prefix Expression: \n");
            puts(prefix);
            break;
        default:
            printf("Invalid Choice");
        }
        printf("\nDo you want to continue ? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
    return 0;
}