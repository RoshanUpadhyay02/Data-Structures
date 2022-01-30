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

    for(i=0;i<rows;i++)
    {
        sum[i][0] = 0;
        for(j=0;j<cols;j++)
        {
            sum[i][0] += a[i][j]; 
        }
    }

    printf("Sum of each row of the matrix: \n");
    for(i=0;i<rows;i++)
    {
        printf("%d\n",sum[i][0]);
    }

    return 0;
}