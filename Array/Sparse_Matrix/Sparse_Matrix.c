#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,col,i,j,k=1;
    printf("Enter the row and columns: ");
    scanf("%d %d",&row,&col);

    int matrix[row][col], sparse[row][col];

    printf("Enter the matrix: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            scanf("%d",&matrix[i][j]);
    }

    printf("\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }

    }

    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = k-1;

    printf("\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",sparse[i][j]);
        printf("\n");
    }

    return 0;
}