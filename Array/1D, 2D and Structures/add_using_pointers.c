#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, i,j;
    printf("Enter the row and the column values: ");
    scanf("%d %d",&row,&col);

    int a[row][col], b[row][col], sum[row][col];
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

    printf("\nThe Sum of (a) and (b) is: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d ",*(*(sum+i)+j) = *(*(a+i)+j) + *(*(b+i)+j));
        printf("\n");
    }

    return 0;
}