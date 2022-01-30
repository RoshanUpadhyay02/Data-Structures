#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows,cols,i,j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&rows,&cols);

    int a[rows][cols],sum[rows][1];
    printf("Enter the Elements: \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("\nLower Triangle of Square Matrix: \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            if(i<=j)
                printf("%d ",a[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}