#include <stdio.h>
#include <stdlib.h>

int search(int *a, int n, int value)
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        //int mid = (low + high)/2;
        int mid = low + (high - low)/2;
        if(*(a+mid) == value)
            return mid;
        if(value > *(a+mid))
            low = mid + 1;
        else
            high = mid-1;
    }
        
    return -1;
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

    printf("Array elements: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
    
    //system("CLS");

    printf("\nEnter the element to be found: ");
    scanf("%d",&x);
    

    r = search(a,n,x);
    if(r == -1)
        printf("Element Not Found");
    else
        printf("Element Found at position: %d",r+1);

    return 0;
}