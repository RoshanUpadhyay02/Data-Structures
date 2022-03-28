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

int inorder(struct node *root)
{
    if(root == NULL)
        return 0;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int postorder(struct node *root)
{
    if(root == NULL)
        return 0;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
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

    printf("\n\nThe Inorder Traversal is: ");
    inorder(root);

    printf("\n\nThe Postorder Traversal is: ");
    postorder(root);

    printf("\n\nBinary Search Tree: \n");
    display(root,0);

    return 0;
}