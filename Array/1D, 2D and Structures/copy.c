#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the no. of elements in the array: ");
    scanf("%d",&n);

    int *a,*b,i;
    a = (int *)malloc(n*sizeof(int));
    b = (int *)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    b = a;

    printf("\n (a) array elements: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    printf("\n (b) array elements: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(b+i));
    }

    return 0;
}