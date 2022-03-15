#include <stdio.h>

void TOH(int n,char S,char D,char A)
{
    if(n>0)
    {
        TOH(n-1,S,A,D);
        printf("move %c->%c\n",S,D);
        TOH(n-1,A,D,S);
    }
}

int main()
{
    int n;
    printf("Enter the no. of discs: ");
    scanf("%d",&n);
    TOH(n,'S','D','A');
}