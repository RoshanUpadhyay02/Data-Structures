#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top;

void push(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(top == NULL)
        top = newnode;
    else
    {
        newnode->next = top;
        top = newnode;
    }
}

void pop()
{
    printf("\n\nThe popped element is: %d",top->data);
    printf("\n");
    top = top->next;
}

void display()
{
    printf("\nThe elements in the stack are : \n");
    struct node *temp = top;
    while(temp != NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    int n,i,x;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(x);
    }

    display();

    pop();

    display();

    return 0;
}