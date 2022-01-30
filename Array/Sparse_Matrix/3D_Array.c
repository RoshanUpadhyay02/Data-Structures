#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,rows,cols,i,j,k;
    printf("Enter the n,rows,columns of the 3D matrix: ");
    scanf("%d %d %d",&n,&rows,&cols);

    int a[n][rows][cols];
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<rows;j++)
        {
            for(k=0;k<cols;k++)
            {
                scanf("%d",&a[i][j][k]);
            }
        }
    }

    printf("\n3D Array: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<rows;j++)
        {
            for(k=0;k<cols;k++)
            {
                //printf("%d ",a[i][j][k]);
                printf("%d ",*(*(*(a+i)+j)+k));
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}