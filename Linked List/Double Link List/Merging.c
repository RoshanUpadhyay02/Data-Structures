#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head1,*last1,*head2,*last2,*head3,*last3;

void insert(struct node **head,struct node **last,int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(*head == NULL)    {
       *head = newnode;
       *last = *head;
    }
    else
    {
        while((*last)->next != NULL)
        {
            *last = (*last)->next;
        }
        (*last)->next = newnode;
        newnode->prev = (*last);
        (*last) = newnode;
    }
}

struct node *merge_h(struct node *temp1, struct node *temp2)
{
    if (temp1 == NULL)
        return temp2;

    else if (temp2 == NULL)
        return temp1;

    struct node *head = NULL;

    if(temp1->data <= temp2->data)
    {
        head = temp1;
        head->next = merge_h(temp1->next,temp2);
    }
    else
    {
        head = temp2;
        head->next = merge_h(temp1,temp2->next);
    }

    return head;
}

struct node *merge_l(struct node *temp1, struct node *temp2)
{
    if (temp1 == NULL)
        return temp2;

    else if (temp2 == NULL)
        return temp1;

    struct node *last = NULL;

    if(temp1->data >= temp2->data)
    {
        last = temp1;
        last->prev = merge_l(temp1->prev,temp2);
    }
    else
    {
        last = temp2;
        last->prev = merge_l(temp1,temp2->prev);
    }

    return last;
}


void display(struct node **head)
{
    struct node *temp = *head;
    while(temp != NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void display__r(struct node **last)
{
    struct node *temp = *last;
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
    printf("Enter the no. of elements in the 1st list: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    while(n--)
    {
        scanf("%d",&x);
        insert(&head1,&last1, x);
    }

    display(&head1);

    printf("\nEnter the no. of elements in the 2nd list: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    while(n--)
    {
        scanf("%d",&x);
        insert(&head2,&last2, x);
    }

    display(&head2);

    printf("\n\n**Merging the 2 lists**\n");
    head3 = merge_h(head1,head2);
    last3 = merge_l(last1,last2);
    
    display(&head3);

    printf("\nReverse: \n");
    display__r(&last3);

    return 0;
}