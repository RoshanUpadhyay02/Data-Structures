#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("Enter the elements in the array: ");
    scanf("%d",&n);

    int *a;
    a = (int *)malloc((n+1)*sizeof(int));

    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    printf("Array before insertion: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    int x,y;
    printf("\nEnter the number and position: ");
    scanf("%d %d",&x,&y);
    y--;

    for(i=n+1;i>y;i--)
    {
        *(a+i) = *(a+i-1);
    }

    *(a+y) = x;

    printf("\nArray after insertion: ");
    for(i=0;i<n+1;i++)
    {
        printf("%d ",*(a+i));
    }

    return 0;
}