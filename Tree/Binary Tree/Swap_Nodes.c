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
    newnode = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("\nEnter the value: ");
    scanf("%d",&value);

    if(value == -1)
        return NULL;

    newnode->data = value;
    printf("Enter the left node of: %d",value);
    newnode->left = insert();
    printf("Enter the right node of: %d",value);
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

int display(struct node *root,int level)
{
    int i;
    if(root == NULL)
        return 0;
    else
    {
        display(root->right,level+1);
        printf("\n");
        for(i=0;i<level;i++)
            printf("    ");
        printf("%d",root->data);
        display(root->left,level+1);
    }
}

void swapTree(struct node *root)
{
    struct node *temp;
	if(root == NULL) 
        return;

	temp = root->left;
	root->left=root->right;
	root->right=temp;
	swapTree(root->left);
	swapTree(root->right);
}

int main()
{
    int n;
    root = (struct node *)malloc(sizeof(struct node));
    printf("Enter the root node: ");
    root = insert();

    printf("The Binary Tree is:\n");
    preorder(root);

    printf("\n\nThe Binary Tree is:\n");
    display(root,0);

    swapTree(root);

    printf("\n\nThe Binary Tree is:\n");
    preorder(root);

    printf("\nThe Binary Tree is:\n");
    display(root,0);

    return 0;
}