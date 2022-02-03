#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head1,*head2,*head3;

void insert(struct node **head, int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(*head == NULL)
        *head = newnode;
    else
    {
       struct node *temp = *head;
       while(temp->next != NULL)
       {
           temp = temp->next;
       }
       temp->next = newnode;
    }
}

struct node *merge(struct node *temp1, struct node *temp2)
{
    if (temp1 == NULL)
        return temp2;

    else if (temp2 == NULL)
        return temp1;

    struct node *head = NULL;

    if(temp1->data <= temp2->data)
    {
        head = temp1;
        head->next = merge(temp1->next,temp2);
    }
    else
    {
        head = temp2;
        head->next = merge(temp1,temp2->next);
    }

    return head;
}

// struct node *merge()
// {
//     struct node *temp1=head1,*temp2=head2,*temp3=head3;
//     while(temp1->next != NULL && temp2->next == NULL)
//     {
//         if(temp1->data < temp2->data)
//         {
//             if(head3 == NULL)
//             {
//                 insert(&head3,temp1->data);
//                 temp1 = temp1->next;
//             }
//             else
//             {
//                 insert(&temp3,temp1->data);
//                 if(temp3 != NULL)
//                     temp3 = temp3->next;
//                 temp1 = temp1->next;
//             }
//         }
//         else if(temp1->data = temp2->data)
//         {
//             if(head3 == NULL)
//             {
//                 insert(&head3,temp1->data);
//                 temp1 = temp1->next;
//                 temp2 = temp2->next;
//             }
//             else
//             {
//                 insert(&temp3,temp1->data);
//                 temp1 = temp1->next;
//                 if(temp3 != NULL)
//                     temp3 = temp3->next;
//                 temp2 = temp2->next;
//             }
            
//         }
//         else if(temp1->data > temp2->data)
//         {
//             if(head3 == NULL)
//             {
//                 insert(&head3,temp2->data);
//                 temp2 = temp2->next;
//             }
//             else
//             {
//                 insert(&temp3,temp2->data);
//                 if(temp3 != NULL)
//                     temp3 = temp3->next;
//                 temp2 = temp2->next;
//             }
//         }
//     }
//     return temp3;
// }

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

int main()
{
    int n,x;
    printf("Enter the no. of elements in the 1st list: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    while(n--)
    {
        scanf("%d",&x);
        insert(&head1, x);
    }

    display(&head1);

    printf("\nEnter the no. of elements in the 2nd list: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    while(n--)
    {
        scanf("%d",&x);
        insert(&head2, x);
    }

    display(&head2);

    printf("\n\n**Merging the 2 lists**\n");
    head3 = merge(head1,head2);
    //head3 = merge();
    
    display(&head3);

    return 0;
}