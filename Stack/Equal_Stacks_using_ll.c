#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top1,*top2,*top3;

int push(struct node **top,int s,int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    s += value;

    if(*top == NULL)
        *top = newnode;
    else
    {
        newnode->next = *top;
        *top = newnode;
    }
    return s;
}

int pop(struct node **top)
{
    int temp = (*top)->data;
    *top = (*top)->next;
    return temp;
}

void display(struct node **top)
{
    struct node *temp = *top;
    while(temp != NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int findmax(int s1, int s2, int s3)
{
    if(s1 > s2 && s1 > s3)
        return 1;
    else if(s2 > s1 && s2 > s3)
        return 2;
    else
        return 3;
}

int findsum(int s1,int s2,int s3)
{
    while(!(s1 == s2 && s2  == s3))
    {
        int max = findmax(s1,s2,s3);
        if(max == 1)        
            s1 -= pop(&top1);
        else if(max == 2)
            s2 -= pop(&top2);
        else
            s3 -= pop(&top3);
    }

    return s1;
}

int main()
{
    int n,i,x,sum1=0,sum2=0,sum3=0;
    printf("Enter the no. of elements in 1st: ");
    scanf("%d",&n);

    printf("Enter the elements in 1st: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum1 = push(&top1,sum1,x);
    }

    display(&top1);

    printf("\nEnter the no. of elements in 2nd: ");
    scanf("%d",&n);

    printf("Enter the elements in 2nd: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum2 = push(&top2,sum2, x);
    }

    display(&top2);

    printf("\nEnter the no. of elements in 3rd: ");
    scanf("%d",&n);

    printf("Enter the elements in 3rd: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum3 = push(&top3,sum3,x);
    }

    display(&top3);

    int sum = findsum(sum1,sum2,sum3); 

    printf("\n\nThe Max Sum at which the stacks are equal is: %d",sum);

    return 0;
}