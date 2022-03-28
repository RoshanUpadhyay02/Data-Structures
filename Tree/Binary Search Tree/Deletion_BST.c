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

int display(struct node *root, int level)
{
    int i;
    if(root == NULL)
        return 0;
    else
    {
        display(root->right, level+1);
        printf("\n");
        for(i=0;i<level;i++)
            printf("    ");
        printf("%d", root->data);
        display(root->left, level+1);
    }
}

struct node *min(struct node *root)
{
    if(root->left == NULL)
        return root;
    min(root->left);
}

struct node *deletion(struct node *root, int value)
{
    if(root == NULL)
        return root;
    if(value < root->data)
        root->left = deletion(root->left, value);
    else if(value > root->data)
        root->right = deletion(root->right, value);
    else
    {
        // if node has one child or no child
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // if node has two children
        struct node *temp = min(root->right);

        // copy the smallest node in the right subtree to the deleting node
        root->data = temp->data;

        // delete the node which has been copied
        root->right = deletion(root->right, temp->data);

    }

    return root;
}

int main()
{
    int n,i,value,d;
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

    printf("\n\nBinary Search Tree: \n");
    display(root,0);

    printf("\n\nHow many node to be deleted: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n\nEnter the node to be deleted: ");
        scanf("%d",&d);
        root = deletion(root, d);

        printf("\n\nThe Preorder Traversal is: ");
        preorder(root);

        printf("\n\nBinary Search Tree: \n");
        display(root,0);
    }

    return 0;
}