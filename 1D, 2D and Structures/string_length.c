#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count=0;
    char *a;
    a = (char *)malloc(100*sizeof(char));
    printf("Enter the string: ");
    scanf("%s",a);

    while(*(a++) != '\0')
        count++;

    printf("The length of string is: %d",count);

    return 0;
}