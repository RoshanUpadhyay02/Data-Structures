#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int n)
{
    int i,j,key;
    for(i=1;i<=n;i++)
    {
        key = *(a+i);
        j = i-1;

        while(j >=0 && *(a+j) > key)
        {
            *(a+j+1) = *(a+j);
            j = j-1; 
        }
        *(a+j+1) = key;
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
}