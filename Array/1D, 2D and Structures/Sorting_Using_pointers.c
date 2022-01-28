#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int *b)
{
    int temp  = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter the no. of elements in the array: ");
    scanf("%d",&n);

    int *a,i,j;
    a = (int *)malloc(n*sizeof(int));

    printf("Enter the elements in the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    printf("The array elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(a+i) > *(a+j))
                sort((a+i),(a+j));
        }
    }

    printf("\nThe sorted array elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }

    return 0;
}