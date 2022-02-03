#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void insert(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
       struct node *temp = head;
       while(temp->next != NULL)
       {
           temp = temp->next;
       }
       temp->next = newnode;
    }
}

int search(int target)
{
    struct node *temp = head;
    int count = 0;
    while(temp != NULL)
    {
        ++count;
        if(temp->data == target)
        {
            printf("Value: %d, found at position: %d",temp->data,count);
            return 0;
        }
        else
            temp = temp->next;
    }
    return -1;
}

void display()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    int n,x;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    while(n--)
    {
        scanf("%d",&x);
        insert(x);
    }

    display();

    printf("\n\n**Searching an Element in a Linked List**\n");
    printf("Enter the value to be found: ");
    scanf("%d",&x);
    n = search(x);

    if(n == -1)
        printf("Element Not Found.");

    return 0;
}