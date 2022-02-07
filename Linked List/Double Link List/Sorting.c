#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head,*last;

void insert(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL)    {
        head = newnode;
        last = head;
    }
    else
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
}


void sort()
{
    struct node *i,*j;
    for(i=head;i->next != NULL;i=i->next)
    {
        for(j=head;j->next != NULL;j=j->next)
        {
            if(j->data >j->next->data)
            {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
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

void display__r()
{
    struct node *temp = last;
    while(temp != NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->prev;
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

    printf("\n\n**Sorting a Linked List**\n");
    sort();
    
    display();

    printf("\nReverse: \n");
    display__r();

    return 0;
}