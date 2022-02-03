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

void insert_mid(int value,int pos)
{
    int i;
    struct node *newnode, *temp = head, *temp1;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    for(i=0;i<pos;i++)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = newnode;
    newnode->next = temp;
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

    printf("\n\n**Inserting Node in the Middle**");
    printf("\nEnter the value: ");
    scanf("%d",&x);
    printf("Enter the position: ");
    scanf("%d",&n);
    insert_mid(x,--n);

    display();

    return 0;
}