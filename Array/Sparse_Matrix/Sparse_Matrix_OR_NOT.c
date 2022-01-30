#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows,cols,i,j,count;
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
    
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            if(a[i][j] == 0)
                count++;
        }
    }

    if(count < (rows*cols)/2)
        printf("\nNot Sparse Matrix.");
    else
        printf("\nSparse Matrix.");

    return 0;
}