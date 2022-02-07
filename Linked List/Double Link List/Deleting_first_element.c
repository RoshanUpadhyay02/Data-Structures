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

void delete_f()
{
    struct node *temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
}

void delete_l()
{
    struct node *temp = last;
    last = temp->prev;
    last->next = NULL;
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

    printf("\n\n**Deleting the First Node**\n");

    printf("Please chooose from where the no. has to be deleted\n1.Front\n2.End\n");
    printf("Enter Your Choice: ");
    scanf("%d",&p);
    switch(p)
    {
        case 1:
            delete_f();
            break;
        case 2:
            delete_l();
            break;
        default:
            printf("Please Enter the correct choice!!!");
            break;
    }

    display();

    return 0;
}