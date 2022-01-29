#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j;
    printf("Enter the no. of elements in 1st array: ");
    scanf("%d",&n);

    printf("Enter the no. of elements in 2nd array: ");
    scanf("%d",&m);

    int *a,*b;
    a = (int *)malloc((n+m)*sizeof(int));
    b = (int *)malloc(m*sizeof(int));

    printf("\nEnter the elements of 1st array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    printf("1st Array elements before Merging: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    printf("\n\nEnter the elements of 2nd array: ");
    for(i=0;i<m;i++)
    {
        scanf("%d",(b+i));

    }

    j=n;

    printf("2nd Array elements before Merging: ");
    for(i=0;i<m;i++)
    {
        printf("%d ",*(b+i));
        *(a+j) = *(b+i);
        j++;
    }


    printf("\n\nArray elements after Merging: ");
    for(i=0;i<(n+m);i++)
    {
        printf("%d ",*(a+i));
    }

    return 0;
}