#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);

    int *a,i,sum = 0;
    a = (int *)malloc(n*sizeof(int));

    printf("Enter the Array Elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    printf("Array Elements: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
        sum += *(a+i);
    }
    printf("\nSum = %d",sum);

    return 0;
}