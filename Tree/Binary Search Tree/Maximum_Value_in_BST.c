#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
}*root = NULL;

struct node *newnode(int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node *insert(struct node *root, int key)
{
    if(root == NULL)
        return newnode(key);
    if(key < root->data)
        root->left = insert(root->left,key);
    else
        root->right = insert(root->right,key);

    return root;
}

int preorder(struct node *root)
{
    if(root == NULL)
        return 0;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}


int max(struct node *root)
{
    if(root->right == NULL)
        return root->data;
    max(root->right);
}

int main()
{
    int n,i,value,mi,mx;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the value: ");
        scanf("%d",&value);
        root = insert(root, value);
    }

    printf("\n\nThe Preorder Traversal is: ");
    preorder(root);

    mx = max(root);

    printf("\n\nThe Maximum value is: %d",mx);

    return 0;
}