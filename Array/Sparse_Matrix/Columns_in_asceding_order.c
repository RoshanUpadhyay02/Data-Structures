#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows,cols,i,j,k;
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
            for(k=i+1;k<rows;k++)
            {
                if(a[i][j] > a[k][j])
                {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }

    printf("\nRows in Ascending Order: \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}