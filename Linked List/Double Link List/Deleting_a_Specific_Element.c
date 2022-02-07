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

void delete(int target)
{
    struct node *temp = head, *temp1;
    while(temp->data != target)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = temp->next;
    temp1->next->prev = temp->prev;
    free(temp);

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

    printf("\n\n**Deleting a Specific Node**");
    printf("\nEnter the element to be deleted: ");
    scanf("%d",&x);
    delete(x);

    display();

    printf("\nReverse: \n");
    display__r();

    return 0;
}