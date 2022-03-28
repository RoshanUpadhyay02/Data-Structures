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

// int getHeight(struct node* root) {
//     // Write your code here
//     int leftHeight = 0;
//     int rightHeight = 0;

//     if (root->left != NULL) {
//         leftHeight = 1 + getHeight(root->left);
//     }

//     if (root->right != NULL) {
//         rightHeight = 1 + getHeight(root->right);
//     }

//     return leftHeight > rightHeight ? leftHeight : rightHeight;
// }

int main()
{
    root = (struct node *)malloc(sizeof(struct node));
    printf("Enter the root node\n");
    root = insert();

    printf("\nPreorder Traversal: ");
    preorder(root);

    int h = height(root);
    printf("\nThe height of the binary tree is: %d",h-1);

    return 0;
}