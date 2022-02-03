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

void delete()
{
    struct node *temp = head;
    head = temp->next;
    free(temp);
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

    printf("\n\n**Deleting the First Node**\n");
    delete();

    display();

    return 0;
}