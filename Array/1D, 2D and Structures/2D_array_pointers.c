#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, i,j;
    printf("Enter the row and the column values: ");
    scanf("%d %d",&row,&col);

    int a[row][col];
    printf("Enter the matrix: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",(*(a+i)+j));
        //    scanf("%d",&a[i][j]);
    }

    printf("The Matrix is: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d ",*(*(a+i)+j));
        //    printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;
}