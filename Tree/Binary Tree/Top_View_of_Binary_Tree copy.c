#include <stdio.h>
#include <stdlib.h>

// Array
int t[101], indx = 50;
void array()
{
    int i;
    for(i=0;i<101;i++)
        t[i] = -1;

}

void display_array()
{
    int i;
    for(i=1;i<101;i++)
    {
        if(t[i] != -1)
            printf("%d ",t[i]);
    }
}

//Bianry Tree

struct node
{
    int data;
    struct node *left, *right;
}*root;

struct node *insert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    int value;
    scanf("%d",&value);

    if(value == -1)
        return NULL;

    newnode->data = value;
    printf("Enter the left node of: %d\n",value);
    newnode->left = insert();
    printf("Enter the right node of: %d\n",value);
    newnode->right = insert();

    return newnode;
}

int preorder(struct node *root)
{
    if(root == NULL)
        return 0;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

// Queue

struct Node
{
    int data;
    int index;
    struct Node *next;
}*front=NULL,*rear=NULL;

int count = 0;
void enqueue(struct node *root, int idx)
{
    struct Node* newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = root->data;
    newnode->index = idx;
    newnode->next = NULL;
    count++;
    if(rear == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        struct Node *temp = rear;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    if(root->left != NULL)
        enqueue(root->left,idx-1);
    if(root->right != NULL)
        enqueue(root->right,idx+1);
}

void display()
{
    if(front == NULL && rear == NULL)
        printf("Empty Queue!!");
    else
    {
        printf("\nThe elements in the queue are : \n");
        struct Node *temp = front;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            printf("\t%d\n",temp->index);
            temp = temp->next;
        }
    }
}

void dequeue()
{
    struct Node *temp = front;
    while(temp != NULL)
    {
        if(t[temp->index] == -1)
        {
            t[temp->index] = temp->data;
            temp = temp->next;
        }
        else
            temp = temp->next;
    }
}



int main()
{
    int i;
    root = (struct node*)malloc(sizeof(struct node));
    printf("Enter the root node\n");
    root = insert();

    array();

    enqueue(root, indx);
    display();

    dequeue();
    display_array();

    return 0;
}