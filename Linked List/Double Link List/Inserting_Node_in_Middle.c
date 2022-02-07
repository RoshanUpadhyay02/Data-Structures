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

void insert_mid_f(int value,int pos)
{
    int i;
    struct node *newnode, *temp = head, *temp1;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    for(i=0;i<pos;i++)
    {
        temp1 = temp;
        temp = temp->next;
    }
    newnode->next = temp;
    temp->prev = newnode;
    newnode->prev = temp1;
    temp1->next = newnode;
}

void insert_mid_b(int value,int pos)
{
    int i;
    struct node *newnode, *temp = last, *temp1;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    for(i=0;i<pos;i++)
    {
        temp1 = temp;
        temp = temp->prev;
    }
    newnode->prev = temp;
    temp->next = newnode;
    newnode->next = temp1;
    temp1->prev = newnode;
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
    int n,x,p;
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
    printf("Please chooose from where the no. has to be inserted\n1.Front\n2.End\n");
    printf("Enter Your Choice: ");
    scanf("%d",&p);
    switch(p)
    {
        case 1:
            insert_mid_f(x,--n);
            break;
        case 2:
            insert_mid_b(x,--n);
            break;
        default:
            printf("Please Enter the correct choice!!!");
            break;
    }

    display();

    printf("\nReverse: \n");
    display__r();

    return 0;
}