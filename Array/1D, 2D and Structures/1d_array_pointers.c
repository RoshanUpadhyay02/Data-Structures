#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1st Way
    /*
    int a[5] = {1,2,3,4,5};
    int *p = a, i;
    for(i=0;i<5;i++)
    {
        printf("%d ",*(p+i));
    }
    */

   // 2nd Way
   /*
   int n = 5;
   int a[n],i;
   for(i=0;i<5;i++)
   {
        scanf("%d",(a+i));
   }
   printf("Array Elements: \n");
   for(i=0;i<5;i++)
   {
        printf("%d ",*(a+i));
   }
   */

    // 3rd Way
    
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int *a,i;
    a = (int *)malloc(n*sizeof(int));

    printf("Enter the Elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }

    printf("Array Elements: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
    return 0;
}