#include<stdio.h>
#include<stdlib.h>

int N;
int top = -1;
int *stack;

void push(char item)
{
        stack[++top] = item;
}

char pop()
{
        return(stack[top--]);
}

int match(char a,char b)
{
        if(a=='[' && b==']')
                return 1;
        if(a=='{' && b=='}')
                return 1;
        if(a=='(' && b==')')
                return 1;
        return 0;
}

int check(char exp[] )
{
        int i;
        char temp;
        for(i=0;i<N;i++)
        {
                if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                    push(exp[i]);
                else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
                {
                    temp = pop();
                    if(match(temp, exp[i]) != 1)
                    {
                        printf("Unbalanced Parentheses");
                            return 0;
                    }                        
                }
        }
        if(top == -1)
        {
                printf("Balanced Parentheses\n");
                return 1;
        }
        else
        {
                printf("Unbalanced Parentheses\n");
                return 0;
        }
}

int main()
{
        int n,i;
        printf("Enter the number of characters: ");
        scanf("%d",&n);

        stack = (int *)malloc(n*sizeof(int));

        N  = n;
        char exp[n];

        printf("Enter an algebraic expression : ");
        scanf("%s",exp);

        check(exp);

        return 0;
}