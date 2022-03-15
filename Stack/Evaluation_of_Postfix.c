#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

int *stack,top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;
    printf("Enter the number of characters: ");
    scanf("%d",&n);

    stack = (int *)malloc(n*sizeof(int));

    char exp[n];
    char *e;
    int n1,n2,sum,num;

    printf("Enter the postfix expression : ");
    scanf("%s",exp);

    e = exp;

    while(*e != '\0')
    {
        if(isdigit(*e))  
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n2 = pop();
            printf("%d",n2);
            n1 = pop();
            switch(*e)
            {
            case '+':
            {
                sum = n1 + n2;
                break;
            }
            case '-':
            {
                sum = n1 - n2;
                break;
            }
            case '*':
            {
                sum = n1 * n2;
                break;
            }
            case '/':
            {
                sum = n1 / n2;
                break;
            }
            }
            push(sum);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}

