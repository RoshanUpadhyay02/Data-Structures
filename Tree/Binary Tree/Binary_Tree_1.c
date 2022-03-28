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

int display(struct node *root,int level)
{
    int i;
    if(root == NULL )
        return 0;
    else
    {
        display(root->right, level+1);
        printf("\n");
        for (i=0; i<level; i++)
            printf("    ");
        printf("%d", root->data);
        display(root->left, level+1);
    }
}

int Swap(struct node* root)
{
        struct node* temp;
        if (root==NULL)
            return 0;
        Swap(root->left);
        Swap(root->right);
    temp = root->left;
    root->left = root->right;
    root->left = temp;
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

    printf("\n\nBinary Tree: \n");
    display(root,0);

    Swap(root);

    printf("\n\nBinary Tree After Swapping: \n");
    display(root,0);

    return 0;
}