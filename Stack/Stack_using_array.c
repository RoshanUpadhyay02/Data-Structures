#include <stdio.h>
#include <stdlib.h>

int *stack, top = -1,n;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[--top];
}

void display()
{
    int n = top;
    while(n >= 0)
    {
        printf("%d ",stack[n--]);
    }
    
}

void isfull()
{
    if(top == n)
        printf("Full\n");
    else
        printf("Not Full\n");
}

void isempty()
{
    if(top == -1)
        printf("Empty\n");
    else
        printf("Not Empty\n");
}

int main()
{
    int x,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    stack = (int *)malloc(n*sizeof(int));
    printf("Enter the elements in the stack: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(x);
    }

    printf("\nThe elements in the stack are : \n");
    display();
    printf("\nIs the stack empty: ");
    isempty();
    printf("\nRemoving element from stack: %d",pop());

    printf("\nAfter performing pop operation\n");
    display();

    printf("\nIs the stack empty: ");
    isempty();
    printf("\nIs the full empty: ");
    isfull();

    return 0;
}