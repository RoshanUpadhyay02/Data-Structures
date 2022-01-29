#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,x,pos;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);

    int *a;
    a = (int *)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    printf("\nArray elements before deletion: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    printf("\n\nEnter the value to be deleted from the array: ");
    scanf("%d",&x);

    for(i=0;i<n;i++)
    {
        if(*(a+i) == x)
        {
            pos = i;
        }
    }

    for(i=pos;i<n;i++)
    {
        *(a+i) = *(a+i+1);
    }

    printf("\nArray elements after deletion: ");
    for(i=0;i<n-1;i++)
    {
        printf("%d ",*(a+i));
    }

    return 0;
}