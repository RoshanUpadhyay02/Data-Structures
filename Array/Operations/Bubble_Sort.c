#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(*(a+j) > *(a+j+1))
            {
                int temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
    }
}

int main()
{
    int n,i,x,r;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);

    int *a;
    a = (int *)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    printf("\nArray elements before Sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    sort(a,n);

    printf("\nArray elements after Sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    return 0;
}