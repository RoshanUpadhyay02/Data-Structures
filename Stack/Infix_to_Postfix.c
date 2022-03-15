#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *stack,top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char a)
{
    if(a == '(')
        return 0;
    if(a == '+' || a == '-')
        return 1;
    if(a == '/' || a == '*' || a == '%')
        return 2;
    return 0;
}

int main()
{
    int n;
    printf("Enter the no. of characters: ");
    scanf("%d",&n);

    char exp[n],*e,x;
    stack = (int *)malloc(n*sizeof(int));

    printf("Enter the infix expression: ");
    scanf("%s",exp);

    printf("\nThe Postfix Notaion is: ");

    e = exp;

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);

        else if(*e == '(')
            push(*e);

        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c",x);
        }
        
        else 
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }

        e++;
    }

    while (top != -1)
    {
        printf("%c",pop());
    }

    return 0;
}