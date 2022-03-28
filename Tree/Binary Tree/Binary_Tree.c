#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
}*root;

struct node *insert()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    if(value == -1)
        return NULL;
    newnode->data = value;
    printf("Enter the left node of %d\n",value);
    newnode->left = insert();
    printf("Enter the right node of %d\n",value);
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

int main()
{
    root = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter the root node\n");
    root = insert();

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}