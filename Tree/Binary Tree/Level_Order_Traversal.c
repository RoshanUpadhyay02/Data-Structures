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
    printf("Enter the value: ");
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

int height(struct node *root)
{
    if(root == NULL)
        return 0;
    else
    {
        int lt = height(root->left);
        int rt = height(root->right);

        if(lt > rt)
            return lt + 1;
        else
            return rt + 1;
    }
}

int levelorder(struct node *root, int level)
{
    if(root == NULL)
        return 0;
    else if(level == 1)
        printf("%d ",root->data);
    else if(level > 1)
    {
        levelorder(root->left,level-1);
        levelorder(root->right,level-1);
    }
}

int main()
{
    int i;
    root = (struct node*)malloc(sizeof(struct node));
    printf("Enter the root node\n");
    root = insert();

    int h = height(root);
    printf("\nThe height of the Binary Tree is: %d",h-1);

    printf("\nLevel Order Traversal: \n");
    for(i=1;i<=h;i++)
        levelorder(root,i);

    return 0;
}