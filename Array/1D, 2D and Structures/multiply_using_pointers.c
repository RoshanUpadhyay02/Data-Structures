#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, i,j,k;
    printf("Enter the row and the column values: ");
    scanf("%d %d",&row,&col);

    int a[row][col], b[row][col], sum;
    printf("Enter the matrix (a): \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",(*(a+i)+j));
    }
    

    // printf("The Matrix is (a): \n");
    // for(i=0;i<row;i++)
    // {
    //     for(j=0;j<col;j++)
    //         printf("%d ",*(*(a+i)+j));
    //     printf("\n");
    // }

    printf("Enter the matrix (b): \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",(*(b+i)+j));
    }

    // printf("The Matrix is (b): \n");
    // for(i=0;i<row;i++)
    // {
    //     for(j=0;j<col;j++)
    //         printf("%d ",*(*(b+i)+j));
    //     printf("\n");
    // }

    for(i=0;i<row;i++)
    {
        sum = 0;
        for(j=0;j<col;j++)
        {
            for(k=0;k<col;k++)
                sum += *(*(a+i)+k) * *(*(b+k)+j);
        }
    }

    printf("\nThe Sum of Product of (a) and (b) is: \n");
    printf("%d ",sum);
    return 0;
}