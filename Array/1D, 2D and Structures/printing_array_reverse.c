#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the no. of elements in the array: ");
    scanf("%d",&n);

    int *a,i;
    a = (int *)malloc(n*sizeof(int));

    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    printf("Array Elements: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    printf("\nReversed Array: ");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",*(a+i));
    }

    return 0;
}